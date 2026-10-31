"""Generate Catppuccin accent themes for Ditto (Latte, Frappe, Macchiato, Mocha).

Source of truth: the official palette (catppuccin/palette, palette.json) and the
installed Mocha accent files, which define the key -> palette-role mapping.
The Mocha run must reproduce those installed files byte for byte; that proves the
mapping before it is trusted for the other three flavors.

Usage: python -I gen-catppuccin-themes.py <palette.json> <template-dir> <out-dir> [--check-mocha]
"""
import json
import os
import re
import sys

ACCENTS = ['rosewater', 'flamingo', 'pink', 'mauve', 'red', 'maroon', 'peach',
           'yellow', 'green', 'teal', 'sky', 'sapphire', 'blue', 'lavender']

# Keys whose value is the accent colour of the file being generated.
ACCENT_KEYS = {'CaptionRight', 'ListBoxSelectedText', 'GroupTreeText'}

# Fixed key -> palette role, read from the installed Mocha accent files.
FIXED_ROLES = {
    'CaptionLeft': 'mantle',
    'CaptionLeftTopMost': 'mantle',
    'CaptionRightTopMost': 'sapphire',
    'CaptionLeftNotConnected': 'red',
    'CaptionRightNotConnected': 'red',
    'CaptionTextColor': 'text',
    'ListBoxEvenRowsBG': 'base',
    'ListBoxOddRowsBG': 'surface0',
    'ListBoxEvenRowsText': 'text',
    'ListBoxOddRowsText': 'text',
    'ListBoxSelectedBG': 'surface2',
    'ListBoxSelectedNoFocusBG': 'surface1',
    'ListBoxSelectedNoFocusText': 'subtext0',
    'Border': 'surface2',
    'BorderTopMost': 'lavender',
    'BorderNotConnected': 'red',
    'GroupTreeBG': 'mantle',
    'DescriptionWindowBG': 'base',
    'DescriptionWindowText': 'text',
    'MainWindowBG': 'base',
    'ClipPastedColor': 'green',
    'SearchTextBoxFocusBG': 'base',
    'SearchTextBoxFocusText': 'text',
    'SearchTextBoxFocusBorder': 'lavender',
    'SearchTextHighlight': 'yellow',
}

FLAVORS = ['latte', 'frappe', 'macchiato', 'mocha']
RGB_LINE = re.compile(r'(<(\w+)>)RGB\(\d+, \d+, \d+\)(</\2>)')
HEADER = re.compile(r'Notes = "Catppuccin (\w+) \((\w+)\)"')


def role_rgb(palette, flavor, role):
    c = palette[flavor]['colors'][role]['rgb']
    return f"RGB({c['r']}, {c['g']}, {c['b']})"


def render(template_text, palette, flavor, accent):
    """Swap every colour in a Mocha accent template for the flavor's colour."""
    def swap(match):
        key = match.group(2)
        if key in ACCENT_KEYS:
            role = accent
        elif key in FIXED_ROLES:
            role = FIXED_ROLES[key]
        else:
            raise KeyError(f"unmapped colour key: {key}")
        return match.group(1) + role_rgb(palette, flavor, role) + match.group(3)

    text = RGB_LINE.sub(swap, template_text)
    flavor_name = flavor.capitalize()
    text = HEADER.sub(f'Notes = "Catppuccin {flavor_name} ({accent.capitalize()})"', text)
    return text


def main(argv):
    palette_path, template_dir, out_dir = argv[1], argv[2], argv[3]
    check_mocha = '--check-mocha' in argv
    with open(palette_path, encoding='utf-8') as f:
        palette = json.load(f)

    failures = 0
    for flavor in FLAVORS:
        for accent in ACCENTS:
            template_path = os.path.join(template_dir, f'catppuccin-mocha-{accent}.xml')
            with open(template_path, encoding='utf-8', newline='') as f:
                template = f.read()
            text = render(template, palette, flavor, accent)
            if flavor == 'mocha' and check_mocha:
                if text != template:
                    failures += 1
                    print(f'MISMATCH mocha-{accent}: round trip differs from installed file')
                continue
            out_path = os.path.join(out_dir, f'catppuccin-{flavor}-{accent}.xml')
            with open(out_path, 'w', encoding='utf-8', newline='') as f:
                f.write(text)
    if check_mocha:
        print('mocha round trip: ' + ('OK, 14 of 14 identical' if failures == 0 else f'{failures} differ'))
    return 1 if failures else 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
