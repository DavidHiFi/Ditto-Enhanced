<div align="center">

<img src="https://socialify.git.ci/DavidHiFi/Ditto-Enhanced/image?description=1&font=Inter&language=1&name=1&owner=1&pattern=Plus&theme=Dark" alt="Ditto-Enhanced by DavidHiFi" width="100%">

# Ditto-Enhanced

**A fork of the [Ditto](https://github.com/sabrogden/Ditto) clipboard manager with a rounded, frosted acrylic quick-paste window for Windows 11.**

Everything else is stock Ditto.

<a href="https://github.com/DavidHiFi/Ditto-Enhanced/releases/latest">
<img src="https://img.shields.io/badge/%E2%AC%87%EF%B8%8F%20DOWNLOAD%20LATEST%20RELEASE-2EA043?style=for-the-badge&labelColor=161B22" alt="Download the latest release" height="42">
</a>

<br><br>

<img src="https://img.shields.io/github/v/release/DavidHiFi/Ditto-Enhanced?style=flat-square&label=version&color=8957E5&labelColor=161B22" alt="Latest version">
<img src="https://img.shields.io/github/downloads/DavidHiFi/Ditto-Enhanced/total?style=flat-square&label=downloads&color=1F6FEB&labelColor=161B22" alt="Total downloads">
<img src="https://img.shields.io/badge/platform-Windows%2011-DB6D28?style=flat-square&labelColor=161B22" alt="Platform: Windows 11">

</div>

---

## Installation

1. Install Ditto from the [upstream release](https://github.com/sabrogden/Ditto/releases/latest), or use an install you already have.
2. Quit Ditto.
3. Download `Ditto.exe` from the [latest release](https://github.com/DavidHiFi/Ditto-Enhanced/releases/latest) and replace the one in your Ditto folder. Windows asks for admin rights when Ditto is in Program Files.
4. Start Ditto.

To go back to the stock look, set the environment variable `DITTO_NO_RICE=1` and restart Ditto.

## Features

- **Rounded corners:** the quick-paste window uses Windows 11's rounded corners.
- **Frosted backdrop:** acrylic blur tinted with your Ditto theme's background colour.
- **Dark material:** the window asks Windows for the dark version of the blur.
- **Clean corners:** the square caption border is skipped, so the corners are not clipped.
- **Self-healing:** the frosted look rebuilds every time the window opens, so fullscreen games and Windhawk resets no longer leave it flat or see-through.

<details>
<summary><b>Building from source</b></summary>

<br>

Needs Visual Studio 2022 with the v143 toolset. Upstream projects now target v145, so pass the toolset explicitly:

```powershell
msbuild CP_Main_10.sln /p:Configuration=Release /p:Platform=x64 /p:PlatformToolset=v143
```

</details>

---

## Support development

This fork is free and always will be. If you like the frosted look, a coffee keeps it going.

[![Support DavidHiFi on Ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/davidhifi)

Ditto itself is made by Scott Brogden. You can also [support Ditto upstream](https://www.paypal.com/donate/?item_name=Donation+to+Ditto&cmd=_donations&business=sabrogden%40gmail.com).

## Contributing

Report problems with the frosted window here. Bugs in Ditto itself belong [upstream](https://github.com/sabrogden/Ditto/issues).

<a href="CONTRIBUTING.md">
<img src="https://img.shields.io/badge/%F0%9F%A4%9D%20HOW%20TO%20CONTRIBUTE-8957E5?style=for-the-badge&labelColor=161B22" alt="How to contribute" height="36">
</a>

## Star history

Thanks for the stars and the frosted-window reports.

<a href="https://www.star-history.com/?repos=DavidHiFi%2FDitto-Enhanced&amp;type=date">
  <picture>
    <source media="(prefers-color-scheme: dark)" srcset="https://api.star-history.com/chart?repos=DavidHiFi/Ditto-Enhanced&amp;type=date&amp;theme=dark&amp;legend=top-left" />
    <source media="(prefers-color-scheme: light)" srcset="https://api.star-history.com/chart?repos=DavidHiFi/Ditto-Enhanced&amp;type=date" />
    <img alt="DavidHiFi/Ditto-Enhanced GitHub star history" src="https://api.star-history.com/chart?repos=DavidHiFi/Ditto-Enhanced&amp;type=date" />
  </picture>
</a>

## Credits

- **Author of this fork:** Myself, [DavidHiFi](https://github.com/DavidHiFi)

| Who | What |
|---|---|
| **Scott Brogden and contributors** ([Ditto](https://github.com/sabrogden/Ditto), GPL-3.0) | The whole clipboard manager. This fork only changes how the quick-paste window is drawn. |

Built on [Ditto](https://github.com/sabrogden/Ditto), with [Visual Studio 2022](https://visualstudio.microsoft.com/vs/), [MFC](https://learn.microsoft.com/cpp/mfc/mfc-desktop-applications) and the [Windows DWM API](https://learn.microsoft.com/windows/win32/dwm/dwm-overview).

> Missing or wrong credit? [Open an issue](https://github.com/DavidHiFi/Ditto-Enhanced/issues/new) and I'll fix it.

## Disclaimers

The changes in this fork were developed with AI coding agents, including Claude Code, Codex and OpenCode. No single AI agent made the project. Ditto itself is the work of its original authors, and this fork keeps its GPL-3.0 license.

This build is not signed. Windows SmartScreen may warn the first time you run it.

<div align="center">
<br>
<sub>Not affiliated with the Ditto project. Requires Windows 11.</sub>
</div>
