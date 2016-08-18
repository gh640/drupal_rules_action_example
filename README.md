# Drupal 7 Rules モジュール サンプル

Rules のアクションを定義しています。

利用方法:

1. Drupal 7 のインスタンスにこのモジュールをインストール
    - `git clone https://github.com/gh640/drupal_rules_event_example drupalcafe`
    - `mv hayato DRUPAL_ROOT/sites/all/modules/`
    - `cd DRUPAL_ROOT`
    - `drush en drupalcafe`
2. Rules UI をインストール
    - `drush dl rules`
    - `drush en rules_admin`
3. Rules の管理画面でルールを作成
    - イベントは適当に選択
    - アクションに「 Translate a text 」という項目が追加されているのでこれを選択
    - その他適切に設定
4. 利用できていることを確認
