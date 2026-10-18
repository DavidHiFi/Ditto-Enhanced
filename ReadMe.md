<div align="center">

<img src="https://socialify.git.ci/DavidHiFi/Ditto-Enhanced/image?description=1&font=Inter&language=1&name=1&owner=1&pattern=Plus&theme=Dark" alt="Ditto-Enhanced by DavidHiFi" width="100%">

# Ditto-Enhanced

**A personal fork of Ditto that renders the quick-paste window as a rounded, frosted acrylic surface.**

Frosted acrylic over the active theme, rounded controls, black-fill backdrops for DWM acrylic, immersive dark, and a rebuilt frosted state on every popup so full-screen games and Windhawk resets heal instantly.

<a href="#installation">
<img src="https://img.shields.io/badge/%F0%9F%93%96%20INSTALL%20GUIDE-2EA043?style=for-the-badge&labelColor=161B22" alt="Read the install guide" height="42">
</a>

<br><br>

<img src="https://img.shields.io/github/license/DavidHiFi/Ditto-Enhanced?style=flat-square&label=license&color=8957E5&labelColor=161B22" alt="License">
<img src="https://img.shields.io/badge/platform-Windows-DB6D28?style=flat-square&labelColor=161B22" alt="Platform: Windows">

</div>

---

## Installation

1. Download the upstream [Ditto installer](https://github.com/sabrogden/Ditto/releases/download/3.25.113.0/DittoSetup_3_25_113_0.exe) or the portable zip from the upstream release page.
2. Replace the upstream binary with this fork's build from the repository ZIP, or build from source (see below).

The upstream release is MIT licensed. This fork keeps upstream's GPL-3.0 terms.

> [!NOTE]
> **In development.** This fork modifies the quick-paste window's rendering and does not publish its own releases yet. Follow the upstream install guide and replace the binary with the build from this repo.

---

## Features

- Frosted acrylic quick-paste window with rounded corners.
- Black-fill backdrop for DWM acrylic transparency.
- Immersive dark mode and rebuilt frosted state on every popup.
- `DITTO_NO_RICE=1` launches with the original solid look.

## Building from source

Requires VS 2022 with the v143 toolset.

```powershell
msbuild CP_Main_10.sln /p:Configuration=Release /p:Platform=x64 /p:PlatformToolset=v143
```

---

## Support development

This project is a free personal fork. A coffee keeps it moving.

[![Support DavidHiFi on Ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/davidhifi)

## Contributing

Bug reports and pull requests are welcome. See [CONTRIBUTING.md](CONTRIBUTING.md) for setup and checks.

<a href="CONTRIBUTING.md">
<img src="https://img.shields.io/badge/%F0%9F%A4%9D%20HOW%20TO%20CONTRIBUTE-8957E5?style=for-the-badge&labelColor=161B22" alt="How to contribute" height="36">
</a>

## Star history

Thank you to everyone using this fork and reporting frosted-window fixes.

<a href="https://www.star-history.com/?repos=DavidHiFi%2FDitto-Enhanced&amp;type=date">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://api.star-history.com/chart?repos=DavidHiFi/Ditto-Enhanced&amp;type=date&amp;theme=dark&amp;legend=top-left" />
    <source media="(prefers-color-scheme: light)" srcset="https://api.star-history.com/chart?repos=DavidHiFi/Ditto-Enhanced&amp;type=date" />
    <img alt="DavidHiFi/Ditto-Enhanced GitHub star history" src="https://api.star-history.com/chart?repos=DavidHiFi/Ditto-Enhanced&amp;type=date" />
  </picture>
</a>

## Credits

- **Author:** Myself, [DavidHiFi](https://github.com/DavidHiFi)
- Upstream: [sabrogden/Ditto](https://github.com/sabrogden/Ditto), GPL-3.0

Built on Windows with Visual Studio 2022 and MSBuild.

> Missing or wrong credit? [Open an issue](https://github.com/DavidHiFi/Ditto-Enhanced/issues/new) and I'll fix it.

## Disclaimers

Most of this project's modifications were developed with AI coding agents, including Claude Code, Codex and OpenCode. No single AI agent made the project. The upstream Ditto code is by its original authors.

<div align="center">
<br>
<sub>Not affiliated with sabrogden. This is an independent personal fork. Requires Windows and the upstream Ditto base.</sub>
</div>
