# FdF
This project is about creating a simplified 3D graphic representation of a
relief landscape linking various points (x, y, z) via segments, using __miniLibX__ and __math__ libraries.
### Map View
The coordinates of landscape are stored in a file passed as a parameter to program. Here is an example:

![mapView](https://i.imgur.com/Mgr0WoF.png)

Each number corresponds to a point in space:
* The horizontal position corresponds to its axis.
* The vertical position corresponds to its ordinate.
* The value corresponds to its altitude.
### Compile and run
For compile use ```make``` at the project directory and for run ```./fdf [map_name]```
### Hotkeys
|Action|Key|
|---|---|
|Move up|<kbd>Arrow Up</kbd>|
|Move down|<kbd>Arrow Down</kbd>|
|Move left|<kbd>Arrow Left</kbd>|
|Move right|<kbd>Arrow Right</kbd>|
|Zoom|<kbd>+</kbd> / <kbd>—</kbd>|
|Rotate X|<kbd>Q</kbd> / <kbd>A</kbd>|
|Rotate Y|<kbd>W</kbd> / <kbd>S</kbd>|
|Rotate Z|<kbd>E</kbd> / <kbd>D</kbd>|
|Isometric Projection|<kbd>I</kbd>|
|Paralel Projection|<kbd>P</kbd>|
|Exit|<kbd>ESC</kbd>|
### Rotation in action
![Rotation](https://media.giphy.com/media/iGpGaS3fCESZmlikOM/giphy.gif)
