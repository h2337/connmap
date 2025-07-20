# connmap
connmap is an X11 desktop widget that shows location of your current network peers on a world map.
(Works on Wayland as well!)

<p align="center"> 
  <img src="https://raw.githubusercontent.com/h2337/connmap/refs/heads/master/sample.png">
</p>

## Installation
Clone the repository `git clone https://github.com/h2337/connmap --depth 1`, install the dependencies (see below), run `make install`, then run the resulting executable `./connmap.elf`.

If you want to run it without attaching it to the terminal then add ampersand at the end of the command: `./connmal.elf &`.

You can also add it to your i3wm config to run at startup (make sure it is in the PATH):
```
exec --no-startup-id connmap.elf
```

## Dependencies
Build dependencies: `xlib`, `libxext`, `libxfixes`, `libcairo2`

Installation dependencies: `unzip`

Runtime dependencies: `iproute2`

Installation for Arch Linux:
```
sudo pacman -S --needed iproute2 libx11 libxext libxfixes cairo unzip
```

Installation for Ubuntu:
```
sudo apt install iproute2 libx11-dev libxext-dev libxfixes-dev libcairo2-dev unzip
```

## Config
Installation will create `~/.config/connmap/connmaprc`. Default `connmaprc` looks like this:
```
location_x 20
location_y 500
map_width 1000
black false
update_interval 1
```
- `location_x`/`location_y` specifies the initial widget location in your desktop (you can later drag/drop the widget with mouse if you are not using a desktop environment that treats mouse drag as multi-select).

- `map_width` specifies the custom pixel width of the map. Height is automatically calculated as width/2. Examples:
  - `map_width 500` creates a 500×250px map
  - `map_width 1000` creates a 1000×500px map
  - `map_width 1500` creates a 1500×750px map
  - `map_width 2000` creates a 2000×1000px map

- Setting `black` to true will draw map outline in black instead of white.

- `update_interval` is seconds the application will sleep for before fetching the updated list of network connections.
## Limitations
- Tested only with i3wm, might not work as expected in other DE/WM.

- Only IPv4 is supported.
