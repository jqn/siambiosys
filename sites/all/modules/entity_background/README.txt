Entity background allows you to add background images and parallax to entity items. It's mostly been tested with Paragraphs but you could use it on any entity.

The module supports the following background types: image, color and parallax.

## Installation

### Modules

This installation section is just for the parent entity_background.module. Please refer to each README in each sub-module for more details.

The sub-modules require the following modules:

* [Paragraphs](https://www.drupal.org/project/paragraphs)
* Paragraphs Bundle Permissions (part of Paragraphs module)
* [Paragraphs ID](https://www.drupal.org/project/paragraphs_id)
* [Field group](https://www.drupal.org/project/field_group)
* [Field collection](https://www.drupal.org/project/field_collection)

Drush command:

Download:

`drush dl paragraphs paragraphs_id entity_background ctools field_group field_collection`

## Configuration

The module uses the "field collection" field called `eb_background` which is used to store the background values.

If you're using Paragraphs, you can add this field by going to the "Paragraph Bundles" page, clicking on "Edit bundle" and checking the "Enable entity background" checkbox.

If you want to use this field on any entity type, then simply add it from the existing field drop-down.

## More Information

### Entity Selector Class

The module attaches a background to entities by using CSS classes in the DOM. To get this working for Paragraphs, we had to add a unique class to each paragraph item, for example, `paragraphs-item-23`. The Paragraphs module doesn't add any unique class to paragraph items so we added a little glue code into the Paragraphs pack module. To get classes onto paragraphs, we're using the [Paragraphs ID](https://www.drupal.org/project/paragraphs_id) module. Once enabled it'll add `paragraphs-item-23` to each paragraph item.

### Why is Paragraphs Bundle Permissions Required?

The default Paragraphs module does not define entity permissions on paragraphs. You can't assign a paragraph create, edit or delete permission to a role.

Due to the lack of permissions an anonymous user may be able to edit/delete field collection entities on paragraphs. This happens because field collection checks the permissions on the host entity and by default paragraphs doesn't have any entity permissions.

Luckily, Paragraphs comes with a sub-module called "Paragraphs Bundle Permissions". Just enable and configure this sub-module to fix the issue.
