The Entity background parallax sub-module attaches parallax background to entities using the [parallax.js](http://pixelcog.github.io/parallax.js) library.

## Installation

**Make sure you have followed the instructions in README.txt in the parent module.**

The sub-module requires the following modules:

* [Libraries API](https://www.drupal.org/project/libraries)
* [jQuery Update](https://www.drupal.org/project/jquery_update) (must run 1.10 or higher)

Enable:
`drush en entity_background_parallax`

As mentioned earlier the module uses the [parallax.js](http://pixelcog.github.io/parallax.js) library. Download and extract it into your [libraries directory](https://www.drupal.org/node/1440066).

Once extracted the path should be `sites/all/libraries/parallaxjs/parallax.js`.

## Configuring Parallax

Some style changes may be required to get the Parallax to work. You may need to remove a few background colors on parent DIVs. Please read "[Under The Hood](http://pixelcog.github.io/parallax.js/#underthehood)". on the parallax library page.
