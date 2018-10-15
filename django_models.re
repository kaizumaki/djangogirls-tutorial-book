
= Djangoモデル


さて、ブログの中のポストを格納するものが欲しいですよね。そのために @<tt>{オブジェクト} についてちょっとお話しします。


== オブジェクト


プログラミングには @<tt>{オブジェクト指向プログラミング} という概念があります。 それは、退屈なプログラムを繰り返し書く代わりにモデルになるものを作って、それが他とどう作用するかを定義するという考え方です。



じゃあオブジェクトって何なの？って思いますよね。オブジェクトは状態（プロパティ）と命令（アクション）の塊です。ピンと来ないでしょうから例を挙げましょう。



猫をモデルにしたいときは、@<tt>{猫(Cat)} オブジェクトを作ります。そのプロパティは、@<tt>{色(color)} 、@<tt>{年齢(age)} 、@<tt>{機嫌(mood)}（いい、悪い、眠い）、@<tt>{飼い主(owner)}（ @<tt>{人(Person)} オブジェクトですね、捨て猫ならそのプロパティは空白）です。



@<tt>{猫} のアクションは、@<tt>{喉を鳴らす(purr)} 、@<tt>{引っ掻く(scratch)} 、@<tt>{餌を食べる(feed)}（ @<tt>{キャットフード(CatFood)} などで、それはまた @<tt>{味(taste)} というプロパティを持つ別のオブジェクトになるでしょう。）


//emlist{
Cat
--------
color
age
mood
owner
purr()
scratch()
feed(cat_food)


CatFood
--------
taste
//}


つまり、オブジェクト指向とは実際の物を、プロパティ（ @<tt>{オブジェクト・プロパティ} と呼びます）と命令（ @<tt>{メソッド} と呼びます）を持つコードで表現するという考え方です。



ではブログポストはどういうモデルになるでしょうか。ブログが作りたいんですよね？



それにはブログポストとは何か、それはどんなプロパティがあるかという問いに答えなければなりません。



まず確実なのはブログポストにはコンテンツとタイトルが必要ですね。 それからそれを書いた人が分かるといいでしょう。 最後に、ポストをいつ作成、公開したかも分かるといいですね。


//emlist{
Post
--------
title
text
author
created_date
published_date
//}


ではブログポストがどうなればいいですか？ポストが公開されるといいですよね？



なので @<tt>{publish} メソッドが必要です。



達成したいことが分かったので、Djangoでモデリングの開始です！


== Djangoモデル


オブジェクトが何か分かったので、ブログポストのDjangoモデルを作りましょう。



Djangoのモデルは特別なオブジェクトで、@<tt>{データベース} に格納されます。 データベースはデータの集まりです。 ここにユーザーやブログポストの情報を格納します。 データを格納するのにSQLiteデータベースを使います。 これはDjangoのデフォルトのデータベースで、今はこれで十分です。



データベースの中のモデルは、列（フィールド）と行（データ）があるスプレッドシートと思ってもらっても結構です。


=== 新しいアプリケーションの作成


全部をきちんと整理しておくため、プロジェクトの中に別のアプリケーションを作ります。 初めから全てを整理しておくのはとっても良いことです。 アプリケーションを作るために、次のコマンドをコンソールの中で走らせましょう。（@<tt>{manage.py} ファイルがある @<tt>{djangogirls} ディレクトリでコマンドをタイプしてくださいね）


====[column] Mac OS X and Linux:


//emlist[command-line]{
(myvenv) ~/djangogirls$ python manage.py startapp blog
//}


====[/column]


====[column] Windows:


//emlist[command-line]{
(myvenv) C:\Users\Name\djangogirls> python manage.py startapp blog
//}


====[/column]


新しく @<tt>{blog} ディレクトリが作られて、今沢山のファイルがそこに入っているのに気がついたでしょう。ディレクトリとファイルはこんな風に見えるはずです：


//emlist{
djangogirls
├── blog
│   ├── __init__.py
│   ├── admin.py
│   ├── apps.py
│   ├── migrations
│   │   └── __init__.py
│   ├── models.py
│   ├── tests.py
│   └── views.py
├── db.sqlite3
├── manage.py
├── mysite
│   ├── __init__.py
│   ├── settings.py
│   ├── urls.py
│   └── wsgi.py
└── requirements.txt
//}


アプリケーションを作ったら、Djangoにそれを使うように伝えないといけません。 それは @<tt>{mysite/settings.py} でします。エディタでこれを開いてください。 まず @<tt>{INSTALLED_APPS} を見つけて @<tt>{]} の上に @<tt>{'blog'} という一行を追加します。 そうすると、最終的には以下のようになりますね。


//emlist[mysite/settings.py][python]{
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'blog',
]
//}

=== ブログポストモデルの作成


@<tt>{blog/models.py} ファイルで @<tt>{Model} と呼ばれるオブジェクトを全て定義します。これがブログポストを定義する場所です。



@<tt>{blog/models.py} をエディタで開いて全部削除し、下のコードを書きましょう。


//emlist[blog/models.py][python]{
from django.db import models
from django.utils import timezone


class Post(models.Model):
    author = models.ForeignKey('auth.User', on_delete=models.CASCADE)
    title = models.CharField(max_length=200)
    text = models.TextField()
    created_date = models.DateTimeField(
            default=timezone.now)
    published_date = models.DateTimeField(
            blank=True, null=True)

    def publish(self):
        self.published_date = timezone.now()
        self.save()

    def __str__(self):
        return self.title
//}

//quote{
@<tt>{str} の両側に2つのアンダースコア（ @<tt>{_} ）がちゃんと入っているか確認しましょう。 これはPythonでよく使われて、"ダンダー"（ダブルアンダースコア）と呼ばれます。

//}


難しそうでしょ？でも大丈夫！ちゃんと説明しますから。



@<tt>{from} とか @<tt>{import} で始まる行は全部、他のファイルから何かをちょこっとずつ追加する行です。 なので色んなファイルから必要な部分をコピペする代わりに @<tt>{from ... import ...} で必要部分を入れることができます。



@<tt>{class Post(models.Model):} – この行が今回のモデルを定義します (これが @<tt>{オブジェクト} です)。

 * classはオブジェクトを定義してますよ、ということを示すキーワードです。
 * @<tt>{Post} はモデルの名前で、他の名前をつけることもできます（が、特殊文字と空白は避けなければいけません）。モデルの名前は大文字で始めます。
 * @<tt>{models.Model} はポストがDjango Modelだという意味で、Djangoが、これはデータベースに保存すべきものだと分かるようにしています。



さて今度はプロパティを定義しましょう：@<tt>{title}、@<tt>{text}、@<tt>{created_date}、@<tt>{published_date}、それに @<tt>{author} ですね。 それにはまずフィールドのタイプを決めなければいけません。（テキスト？ 数値？ 日付？ 他のオブジェクト、例えばユーザーとの関係？）

 * @<tt>{models.CharField} – 文字数が制限されたテキストを定義するフィールド
 * @<tt>{models.TextField} – これは制限無しの長いテキスト用です。ブログポストのコンテンツに理想的なフィールドでしょ？
 * @<tt>{models.DateTimeField} – 日付と時間のフィールド
 * @<tt>{models.ForeignKey} – これは他のモデルへのリンク



コードの細かいところまでは説明し出すと時間がかかるので、ここではしませんが、 モデルのフィールドや上記以外の定義のやり方について知りたい方は是非Djangoドキュメントを見てみて下さい。 (https://docs.djangoproject.com/ja/2.0/ref/models/fields/#field-types)



@<tt>{def publish(self):} は何かと言うと、 これこそが先程お話ししたブログを公開するメソッドそのものです。 @<tt>{def} は、これはファンクション（関数）/メソッドという意味です。@<tt>{publish} はメソッドの名前で、 変えることもできます。 メソッドの名前に使っていいのは、英小文字とアンダースコアで、アンダースコアはスペースの代わりに使います。 （例えば、平均価格を計算するメソッドは @<tt>{calculate_average_price} っていう名前にします）



メソッドは通常何かを @<tt>{return} します。 一つの例が @<tt>{__str__} メソッドにあります。 このシナリオでは、@<tt>{__str__()} を呼ぶと、ポストのタイトルのテキスト（@<strong>{string}）が返ってきます。



@<tt>{def publish(self):} と @<tt>{def __str__(self):} の両方が class キーワードに続く行でインデントされているのに気づきましたか？ Pythonにモデルのメソッドだと伝えるために、class キーワードに続く行ではメソッドをインデントしましょう。 そうしないと、メソッドはモデルのものではなくなり、思ってもみない振る舞いをするでしょう。



もしモデルがまだはっきりつかめないようだったら、気軽にコーチに聞いて下さい！ 特にオブジェクトとファンクションを同時に習ったときはとても複雑なのはよく分かってますから。 でも前ほど魔法みたいじゃないといいですけど！


=== データベースにモデルのためのテーブルを作成する


最後のステップは新しいモデルをデータベースに追加することです。 まず、モデルに少し変更があったこと（今作ったこと）をDjangoに知らせましょう。 コンソールで @<tt>{python manage.py makemigrations blog} とタイプします。 こんな感じですね。


//emlist[command-line]{
(myvenv) ~/djangogirls$ python manage.py makemigrations blog
Migrations for 'blog':
  blog/migrations/0001_initial.py:

  - Create model Post
//}


@<strong>{メモ：}編集したファイルを忘れずに保存してくださいね。保存しないと、コンピュータが以前のパージョンのファイルを実行してしまい、思ってもみないエラーメッセージに出くわすかもしれません。



Djangoが作ってくれた移行ファイルを私たちがデータベースに追加すれば完了です。@<tt>{python manage.py migrate blog} とタイプするとこうなるでしょう。


//emlist[command-line]{
(myvenv) ~/djangogirls$ python manage.py migrate blog
Operations to perform:
  Apply all migrations: blog
Running migrations:
  Applying blog.0001_initial... OK
//}


やった～！ポストモデルがデータベースに入りました。どうなったか見たいでしょ？次へ進みましょう！
