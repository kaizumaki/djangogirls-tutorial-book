
= CSSでカワイくしよう!


ブログは作ったものの、まだなんかダサいですよね。かわいくしましょう！そのためにはCSSを使います。


== CSSとは？


Cascading Style Sheets (CSS)とは、HTMLなどのマークアップ言語で書かれたWebサイトの見た目や書式を記述するための言語です。私達のWebページをメイクアップするものとして使います。



でも、またゼロから作りたくないですよね。プログラマーたちがすでに作って無料で公開しているツールを使いましょう。わざわざイチから作り直す必要はないですからね。


== Bootstrapを使いましょう！


Bootstrap は美しいWebサイトを開発するためのHTMLとCSSのフレームワークとしてとても有名です: http://getbootstrap.com/



これは、もともとTwitterのプログラマーが作成したもので、今は、世界中の有志のボランティアで開発されています。


== Bootstrapのインストール


Bootstrap をインストールするため、@<tt>{.html} ファイル (blog/templates/blog/post_list.html) をコードエディタで開き @<tt>{<head>} の中にこれを追加しましょう:


//emlist[blog/templates/blog/post_list.html][html]{
@<seqsplit>{<link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">}
@<seqsplit>{<link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap-theme.min.css">}
//}


これは、あなたのプロジェクトにファイルを追加しているわけではありません。インターネット上にあるファイルを指しているだけです。では、Webサイトを開いてページを再読み込みしてください。



//image[bootstrap1][]{
//}




これだけでずいぶん見た目が良くなりましたね！


== Djangoの静的ファイル


最後に、@<strong>{静的ファイル}と呼ばれるものを詳しく見ていきましょう。 静的ファイルとは、CSSファイルや画像ファイルといった、動的な変更が発生しないファイルのことです。 そのため、これらのファイルはリクエストに依存せず、どのユーザに対しても中身は同じになります。


=== 静的ファイルはプロジェクトのどこに置けばいいの？


Djangoは、ビルトインの "admin" アプリにより、静的ファイルをどこで探せばいいのかわかっています。私たちがやることは、@<tt>{blog} アプリのための静的ファイルを追加することだけです。



そのために、blogアプリの中に @<tt>{static} というフォルダを作ります。


//emlist{
djangogirls
├── blog
│   ├── migrations
│   ├── static
│   └── templates
└── mysite
//}


Djangoは、全てのアプリのフォルダ内の "static" と名づけられた全てのフォルダを自動的に探して、その中身を静的ファイルとして使えるようにします。


== 最初のCSSファイル！


CSSファイルを作って、Webサイトにあなたのスタイルを設定していきましょう。 @<tt>{static} ディレクトリの中に @<tt>{css} というディレクトリを作成しましょう。 そして、その @<tt>{css} ディレクトリの中に @<tt>{blog.css} という新規ファイルを作ります。 準備OK？


//emlist{
djangogirls
└─── blog
     └─── static
          └─── css
               └─── blog.css
//}


ついにCSSを書くときが来ました！　コードエディタで @<tt>{blog/static/css/blog.css} ファイルを開きましょう。



ここではCSSのカスタマイズや学習方法については詳しく説明しません。さらに知りたい場合は、このページの最後に無料のCSSの学習コースを紹介していますので、そちらを参考にしてください。



ただ、せめて少しはここでやってみましょう。 ヘッダーの色を変えてみるのもいいかもしれませんね。 色を理解するために、コンピュータは特殊なコードを使います。 コードは、@<tt>{#} で始まり、6種類のアルファベット（A-F）や数字（0-9）が続きます。 たとえば、青色のコードは @<tt>{#0000FF} です。 カラーコードのサンプルはこのサイト http://www.colorpicker.com/ で確認できます。 @<tt>{red} や @<tt>{green} といった@<href>{http://www.w3schools.com/colors/colors_names.asp,定義済みの色}を利用することもできます.



@<tt>{blog/static/css/blog.css} ファイルに、次のコードを追加しましょう。


//emlist[blog/static/css/blog.css][css]{
h1 a {
    color: #FCA205;
}
//}


@<tt>{h1 a} はCSSセレクタと呼ばれるものです。 @<tt>{h1} 要素の中にある @<tt>{a} 要素にスタイルを適用します、という意味になります。 よって @<tt>{<h1><a href="">link</a></h1>}となっているとき、 @<tt>{h1 a} スタイルが適用されます。 この場合、その要素を @<tt>{#FCA205} に、つまりオレンジ色にしようとしています。 またはあなたの好きな色に変えられます！



CSSファイルには、HTMLファイルの各要素のスタイルを指定していきます。 まずは要素名でもって、その要素を識別します。 HTMLのタグ名は覚えがあるでしょう。 例えば @<tt>{a}, @<tt>{h1}, @<tt>{body} などが要素名の例です。 また、@<tt>{class} 属性や、@<tt>{id} 属性によって要素を識別することができます。 classやidは、あなたが自分で要素につけることができる名前です。 classは要素のグループを定義して、idは特定の要素を指定します。 例えば、次のタグは、タグ名 @<tt>{a}、class名 @<tt>{external_link}、id名 @<tt>{link_to_wiki_page}、どれを使ってもCSSによって識別されます。


//emlist[][html]{
@<seqsplit>{<a href="https://en.wikipedia.org/wiki/Django" class="external_link" id="link_to_wiki_page">}
//}


CSSセレクタについては@<href>{http://www.w3schools.com/cssref/css_selectors.asp,CSS Selectors in w3schools}を見てください。



さて、CSSを追加したことをHTMLテンプレートに教えないといけません。@<tt>{blog/templates/blog/post_list.html} を開いて、先頭にこの行を追加しましょう：


//emlist[blog/templates/blog/post_list.html][html]{
{% load static %}
//}


これで、このテンプレートに静的ファイルを読み込むことができました^^。そして、@<tt>{<head>} と @<tt>{</head>} の中にあるBootstrap CSSファイルのリンクの下に、この行を追加しましょう：


//emlist[blog/templates/blog/post_list.html][html]{
<link rel="stylesheet" href="{% static 'css/blog.css' %}">
//}


ブラウザは上から書いた順番でファイルを読み込むので、記述する箇所はよく確かめる必要があります。 順番が逆になると、私たちが書いたファイルがBootstrapのファイルに上書きされてしまうかもしれません。 これで、テンプレートにCSSファイルがある場所を教えました。



ファイルは次のようになっているはずです：


//emlist[blog/templates/blog/post_list.html][html]{
{% load static %}
<html>
    <head>
        <title>Django Girls blog</title>
        @<seqsplit>{<link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">}
        @<seqsplit>{<link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap-theme.min.css">}
        <link rel="stylesheet" href="{% static 'css/blog.css' %}">
    </head>
    <body>
        <div>
            <h1><a href="/">Django Girls Blog</a></h1>
        </div>

        {% for post in posts %}
            <div>
                <p>published: {{ post.published_date }}</p>
                <h1><a href="">{{ post.title }}</a></h1>
                <p>{{ post.text|linebreaksbr }}</p>
            </div>
        {% endfor %}
    </body>
</html>
//}


保存して、サイトを更新してください。



//image[color2][]{
//}




素晴らしいですね！あとは、左サイドの余白幅を少し広げて、余裕を持たせてあげたらもっと良くなると思いませんか？やってみましょう！


//emlist[blog/static/css/blog.css][css]{
body {
    padding-left: 15px;
}
//}


これをCSSに追加して、保存してください。どのように変化したか、さぁ見てみましょう！



//image[margin2][]{
//}




ヘッダーのフォントを変えてみませんか？ファイル @<tt>{blog/templates/blog/post_list.html} の @<tt>{<head>} タグの中に次の一行を貼り付けましょう。


//emlist[blog/templates/blog/post_list.html][html]{
@<seqsplit>{<link href="//fonts.googleapis.com/css?family=Lobster&subset=latin,latin-ext" rel="stylesheet" type="text/css">}
//}


まずは、このリンクが @<tt>{blog/static/css/blog.css} より前にあることを確かめましょう。この１行は @<b>{Lobster} というフォントをGoogle Fonts (https://www.google.com/fonts) から読み込むということを意味しています。



@<tt>{blog/static/css/blog.css} ファイルの中の、 @<tt>{h1 a} という宣言ブロックを見つけてください（コードは @<tt>{{} と @<tt>{\}} で囲まれています）。 そして、そのカッコの中に @<tt>{font-family: 'Lobster';} と１行追加して、webサイトを更新してみましょう：


//emlist[blog/static/css/blog.css][css]{
h1 a {
    color: #FCA205;
    font-family: 'Lobster';
}
//}


//image[font][]{
//}




素晴らしいです！



前述のように、CSSはクラスの概念を持っています。 それにより、HTMLコードの一部に名前を指定し、他の部分に影響を与えずにこの部分にだけスタイルを適用することができます。 なんて便利なんでしょう！ 例えば、２つのdiv要素（ヘッダーと記事など）があったとして、これらのそれぞれに違うスタイルを適用することができます。 クラスを利用すると、違う見た目にできるのです。



先に進んで、HTMLコードの一部に名前をつけましょう。ヘッダーを含む@<tt>{div} 要素に、@<tt>{page-header} というクラス名をつけましょう：


//emlist[blog/templates/blog/post_list.html][html]{
<div class="page-header">
    <h1><a href="/">Django Girls Blog</a></h1>
</div>
//}


さらにブログ投稿を含む @<tt>{div} 要素に @<tt>{post} というクラス名をつけましょう。


//emlist[blog/templates/blog/post_list.html][html]{
<div class="post">
    <p>published: {{ post.published_date }}</p>
    <h1><a href="">{{ post.title }}</a></h1>
    <p>{{ post.text|linebreaksbr }}</p>
</div>
//}


そして、さまざまなセレクタに宣言ブロックを追加します。 @<tt>{.} で始まるセレクタはクラスに関連します。 Web上にはCSSに関する多くのチュートリアルがあり、それらは以下に示すコードを理解する手助けになるはずです。 今のところは、@<tt>{blog/static/css/blog.css} のファイルに以下の内容をコピー＆ペーストしましょう：


//emlist[blog/static/css/blog.css][css]{
.page-header {
    background-color: #ff9400;
    margin-top: 0;
    padding: 20px 20px 20px 40px;
}

.page-header h1,
.page-header h1 a,
.page-header h1 a:visited,
.page-header h1 a:active {
    color: #ffffff;
    font-size: 36pt;
    text-decoration: none;
}

.content {
    margin-left: 40px;
}

h1, h2, h3, h4 {
    font-family: 'Lobster', cursive;
}

.date {
    color: #828282;
}

.save {
    float: right;
}

.post-form textarea, .post-form input {
    width: 100%;
}

.top-menu, .top-menu:hover, .top-menu:visited {
    color: #ffffff;
    float: right;
    font-size: 26pt;
    margin-right: 20px;
}

.post {
    margin-bottom: 70px;
}

.post h1 a, .post h1 a:visited {
    color: #000000;
}
//}


では、投稿を表示しているHTMLコードをクラス宣言で囲みましょう。 @<tt>{blog/templates/blog/post_list.html} 中のこの部分を


//emlist[blog/templates/blog/post_list.html][html]{
{% for post in posts %}
    <div class="post">
        <p>published: {{ post.published_date }}</p>
        <h1><a href="">{{ post.title }}</a></h1>
        <p>{{ post.text|linebreaksbr }}</p>
    </div>
{% endfor %}
//}


これで置き換えて下さい：


//emlist[blog/templates/blog/post_list.html][html]{
<div class="content container">
    <div class="row">
        <div class="col-md-8">
            {% for post in posts %}
                <div class="post">
                    <div class="date">
                        <p>published: {{ post.published_date }}</p>
                    </div>
                    <h1><a href="">{{ post.title }}</a></h1>
                    <p>{{ post.text|linebreaksbr }}</p>
                </div>
            {% endfor %}
        </div>
    </div>
</div>
//}


ファイルを保存してWebサイトを更新してみましょう。



//image[final][]{
//}




やったー！ ほら凄いでしょ？ 貼り付けたコードを見て、HTMLにクラスを追加した場所やそのクラスがCSSの中で使われている場所を探してみましょう。 日付の色をターコイズブルーにするには、どこを変更すればいいでしょうか？



CSSをいじって表示が壊れることを恐れないで、どんどん変更を加えてみてください。 CSSで遊んでみることで、何がどうなっているかを理解できてきます。 たとえ何かを壊してしまっても、心配しないで！すぐに元に戻すことができます。



この章の最後に、@<href>{https://www.codecademy.com/tracks/web,Codeacademy HTML & CSS course}という無料のオンライン講座を受講することをおすすめします。 webサイトをCSSで美しくするための多くのことが学べます。



さて、次の章にいく準備はできましたか？^皿^

