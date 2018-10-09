
= Djangoテンプレート


何かデータを表示しましょう！Djangoはそれをビルトインの @<strong>{テンプレートタグ} で実現できます。


== テンプレートタグとは？


HTML中で本当はPythonのコードを書くことはできません。なぜならブラウザが理解できないからです。ブラウザはHTMLだけ分かります。HTMLはどちらかというと静的で、それに対してPythonはもっとずっと動的なことを私たちは知っています。



@<strong>{Djangoテンプレートタグ} はHTMLにPyhtonのようなコードを埋め込むことができて、動的なウェブサイトがより早く簡単に作れます!


== ブログ一覧テンプレートの表示


前の章で、@<tt>{posts} 変数でテンプレートに記事のリストを渡しました。今からHTMLで表示をしてみましょう。



Djangoテンプレートで変数を表示するためには、次のように変数の名前を二重中括弧で括ります。


//emlist[blog/templates/blog/post_list.html][html]{
{{ posts }}
//}


これを @<tt>{blog/templates/blog/post_list.html} テンプレートでやってみましょう。 エディタでこのファイルを開き、２つめと３つめの @<tt>{<div></div>} タグをまるごと @<tt>{{{posts\}\}} に置き換えて下さい。 ファイルを保存してページをリロードしますと：



//image[step1-2][]{
//}




見たとおり、このようになります。


//emlist[blog/templates/blog/post_list.html][html]{
<QuerySet [<Post: My second post>, <Post: My first post>]>
//}


Djangoはposts変数をオブジェクトのリストと認識します。 @<strong>{Python入門}でどうやってリストを表示できたか覚えていますか？ ループを使ってリストを表示しましたよね。 Djangoテンプレートではこう書きます：


//emlist[blog/templates/blog/post_list.html][html]{
{% for post in posts %}
    {{ post }}
{% endfor %}
//}


これをブログのテンプレートで使ってみましょう。



//image[step2-2][]{
//}




動きましたね。 しかし、本当は@<strong>{HTML入門}で作った静的な記事のように表示してほしいところです。 そこで、HTMLとテンプレートタグを混ぜてみましょう。 @<tt>{body} タグの中を次のように書いてください：


//emlist[blog/templates/blog/post_list.html][html]{
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
//}


@<tt>{{% for %\}} と @<tt>{{% endfor %\}} の間に書いたものはリスト中の各オブジェクトの分だけ繰り返されます。ページをリロードしてみましょう。



//image[step3-2][]{
//}




post変数がさっきと違って、@<tt>{{{ post.title \}\}} や @<tt>{{{ post.text \}\}} になっていることに気づきましたか？ @<tt>{Post} モデルで定義したそれぞれのフィールドにアクセスしています。 @<tt>{|linebreaksbr} はpostのテキスト中の改行を段落に変換するフィルタに通すという意味です。


== もう一つ...


今の時点でのウェブサイトを公開して見てみませんか？もう一度PythonAnywhereでデプロイしてみましょう。デプロイのステップをおさらいします。

 * まず、GithubにあなたのコードをPushしましょう


//cmd[command-line]{
$ git status
[...]
$ git add --all .
$ git status
[...]
$ git commit -m "Modified templates to display posts from database."
[...]
$ git push
//}

 * そしたら、@<href>{https://www.pythonanywhere.com/consoles/,PythonAnywhere}に戻って、@<strong>{Bashコンソール}（か、新しいコンソール）に入って、次のようにコマンドを打ちましょう：


//cmd[PythonAnywhere command-line]{
$ cd $USER.pythonanywhere.com
$ git pull
[...]
//}

 * 最後に@<href>{https://www.pythonanywhere.com/web_app_setup/,「Web」ページ}を開いてアプリを@<strong>{リロード}します。 （コンソールから他のPythonAnywhereページにアクセスするには、右上のメニューボタンを使います。）更新された内容がhttps://yourname.pythonanywhere.comに公開されているはずです。ブラウザで確認しましょう！ PythonAnywhereサイトで表示されるブログの記事が、あなたのパソコンの中のローカルサーバーのものと違っていても大丈夫です。 ローカルコンピュータにあるデータベースと、PythonAnywhere上のデータベースは同期していません。



おめでとうございます！よくできました! これができたら、Django adminとして新しい投稿を追加しましょう（published_dateを忘れないで！）。PythonAnywhereサイトのDjango管理者であることを確認してください（https://yourname.pythonanywhere.com/admin ）。それから、投稿したものがそこに見えるか、リロードしましょう。



動くのが楽しくなってきたでしょう？少しパソコンから離れて、休憩しましょう：）



//image[donut][]{
//}
