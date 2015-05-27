# What is Edgy

Edgy allows site builders to display Paragraph items edge-to-edge. It does this by controlling the placement of the .container ([Bootstrap](http://getbootstrap.com/css/#overview-container)) class.

Using a combination of Paragraphs, Panelizer and Edgy, site builders can create powerful edge-to-edge landing pages. Bootstrap is not a requirement and any theme can be used, however, just make sure you have a container class which centers content.

We use Edgy only with Bootstrap 3 using the Radix theme.

# Installation

## Step 1: Make theme edgy aware

You can't simply enable the module and have edge-to-edge content. You must make your theme edgy aware.

- Add the following code into your template.php in the hook_preprocess_page.

<code>
function hook_preprocess_page(&$variables) {
  // Determine if the page is rendered using panels.
  $variables['is_panel'] = FALSE;
  if (module_exists('page_manager') && count(page_manager_get_current_page())) {
    $variables['is_panel'] = TRUE;
  }
}
</code>

- Once you've finish up hook_preprocess_page, now add the following into the page.tpl.php.

<code>
    <div id="content" class="<?php print (!$is_panel) ? 'container' : ''; ?>">
      <?php print render($page['content']); ?>
    </div>
</code>

## Step 2: Configure Panelizer.

- Enable Edgy, Paragraphs and Panelizer.
- In Panelizer configure your edge-to-edge content type using the "Full page override" option.
- Add the Edgy style in Panelizer via the "Display settings".
- Optional: Use the Edgy boxton layout for Panelizer.

# Features

- Edgy style plugin for Panelizer.
- Edgy boxton layout for Panelizer.
- "Edgy one column" layout for Display Suite.
- Customise container class name via "admin/config/system/edgy".

# Requirements

- Paragraphs
- Panelizer
