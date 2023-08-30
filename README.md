# SimpleWaveFunctionCollapse
A simple Wave Function Collapse algorithm implementation for learning purposes and future use.

This small project is born as an excuse to learn the Wave Function Collapse algorithm in the application of a simple map generator.
Moreover, Qt is used for learning purposes even though the goal is to provide a portable and independent C++ 14 implementation of the algorithm.

The overall plan is to use a Qt UI to simulate a 2D squared map. The map will be divided in a grid pattern and each section will be interactable and ready to accept a Tile.

A Tile will be modeled as a button widget with an icon representing that map section's appearance.
Each different icon will come with constraints to decide which other icons can be adjacent to it.
Using the set of constraints thereby deduced, each change in the map status (triggered by the user manually or automatically) will propagate with compatible Tiles.
