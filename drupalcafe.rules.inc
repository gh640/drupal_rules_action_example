<?php

/**
 * Implements hook_rules_action_info().
 */
function drupalcafe_rules_action_info() {

  $actions = [];

  // 与えられたテキストを翻訳するアクション
  $actions['drupalcafe_rules_translate_text'] = [
    'label' => t('Translate a text'),
    'group' => t('DrupalCafe Additional Rules'),
    'parameter' => [
      'text_source' => [
        'type' => 'text',
        'label' => t('Source text'),
        'description' => t('The text to be translated.'),
      ],
    ],
    'provides' => [
      'text_translated' => [
        'type' => 'text',
        'label' => t('The text translated.'),
      ],
    ],
  ];

  // SKU を文字列で、数量を数値で指定したらカートに追加可能なラインアイテムを作成するアクション
  if (module_exists('commerce_line_item') && module_exists('commerce_product')) {
    $actions['drupalcafe_rules_get_line_item'] = [
      'label' => t('Get a commerce line item by SKU'),
      'parameter' => [
        'sku' => [
          'type' => 'text',
          'label' => t('Product SKU'),
          'description' => t('The SKU of the product to add to the cart.'),
        ],
        'quantity' => [
          'type' => 'integer',
          'label' => t('Quantity'),
          'default value' => 1,
        ],
      ],
      'provides' => [
        'commerce_line_item' => [
          'type' => 'commerce_line_item',
          'label' => t('Commerce Line item'),
        ],
      ],
      'group' => t('DrupalCafe Commerce Additional Rules'),
      'callbacks' => [
        'execute' => 'drupalcafe_rules_get_line_item',
      ],
    ];
  }

  return $actions;
}


/**
 * Rules action: テキストを翻訳する
 *
 * @param string $text_source
 *   翻訳元テキスト。
 *
 * @return string
 *   翻訳後テキスト。
 *
 * @see rules_i18n_action_t()
 * @see rules_i18n_rules_action_info()
 */
function drupalcafe_rules_translate_text($text_source) {
  return ['text_translated' => t($text_source)];
}


/**
 * Rules action: 指定された SKU を格納したラインアイテムを生成する
 *
 * @param string $sku
 *   対象となるプロダクトの SKU 。
 * @param int $quantity
 *   ラインアイテムで指定したい数量。
 *
 * @return object
 *   指定されたプロダクトを含むラインアイテムオブジェクト。
 */
function drupalcafe_rules_get_line_item($sku, $quantity) {
  // （省略）パラメータを検証
  // （省略）ラインアイテムを生成
  return $line_item;
}
