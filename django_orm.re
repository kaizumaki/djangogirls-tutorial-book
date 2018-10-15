
= DjangoのORMとクエリセット


この章では、Djangoのデータベース接続方法と、データの格納について学びます。やってみましょう！


== クエリセットとは？


クエリセットが何かと言うと、モデルのオブジェクトのリストのことです。クエリセットを使って、データベースからデータを読み込んだり、抽出したり、並べ替えたりできます。



実際に動かしてみるのが一番わかりやすいので、試してみましょう。


== Django shell


コンソール画面を開いて（PythonAnywhereのコンソールではないですよ）、次のコマンドを入力してみましょう。


//emlist[command-line]{
(myvenv) ~/djangogirls$ python manage.py shell
//}


次のような表示に切り替わるでしょう。


//emlist[command-line]{
(InteractiveConsole)
>>>
//}


今、Djangoのインタラクティブコンソールが起動しています。Pythonプロンプトしかないように見えますが、ちゃんとDjangoも動いています。このコンソール画面では、Pythonのコマンドは何でも使えます。


=== すべてのオブジェクト


最初に、ポストデータを全部表示させてみましょう。次のコマンドで、ポストのデータを全部表示させることが出来ます。


//emlist[command-line]{
>>> Post.objects.all()
Traceback (most recent call last):
      File "<console>", line 1, in <module>
NameError: name 'Post' is not defined
//}


ごめんなさい、エラーになってしまいましたね。Postがないというエラーです。その通りなんです。最初にインポートをしなくてはならないのに、忘れていました。


//emlist[command-line]{
>>> from blog.models import Post
//}


こんな風に書くだけで、@<tt>{blog.models} から @<tt>{Post} モデルをインポート出来ます。それでは、もう一度試してみましょう。


//emlist[command-line]{
>>> Post.objects.all()
<QuerySet [<Post: my post title>, <Post: another post title>]>
//}


さっきDjangoの管理画面から作ったポストのリストが表示されました。だけど、次はこのコンソール画面から、新たにポストを作ってみたいですよね。それはどうすればいいのでしょうか。


=== オブジェクトの作成


データベースに、新しいPostを作成するには、次のようにします。


//emlist[command-line]{
>>> Post.objects.create(author=me, title='Sample title', text='Test')
//}


いい感じなのですが、1つだけマズイことをしているんです。author に @<tt>{me} を渡していますが、これは @<tt>{User} モデルのインスタンスでないといけませんよね。それは、どうやればいいと思います？



そうです、さっきと同じです。Userモデルも先にインポートしておきましょう。


//emlist[command-line]{
>>> from django.contrib.auth.models import User
//}


どんなユーザが、データベースに登録されてましたっけ？覗いてみましょうか。


//emlist[command-line]{
>>> User.objects.all()
<QuerySet [<User: ola>]>
//}


作成しておいたスーパーユーザがいますね。このユーザを取り出してみましょう（この行をご自身で作ったスーパーユーザのユーザ名に変更して取り出してくださいね）。


//emlist[command-line]{
>>> me = User.objects.get(username='ola')
//}


ola という @<tt>{ユーザ名} の @<tt>{User} モデルのインスタンスを、@<tt>{取り出せ} たでしょう？よかった！



さあ、遂にコンソール画面から、最初のポストを作成出来ますね。


//emlist[command-line]{
>>> Post.objects.create(author=me, title='Sample title', text='Test')
<Post: Sample title>
//}


どうでしょうか？ちゃんと出来ているか、確認しておきましょうね。


//emlist[command-line]{
>>> Post.objects.all()
@<seqsplit>{<QuerySet [<Post: my post title>, <Post: another post title>, <Post: Sample title>]>}
//}


出来ていますね！リストにはポストが1つ以上あります。


=== さらに投稿を追加しましょう


楽しくなってきたでしょう？理解を深めるためにもう少しポストを作っておきましょう。2〜3個記事を追加したら、次に進みましょう。


=== オブジェクトの抽出


クエリセットの大部分は、抽出機能だと言えるでしょう。 ユーザolaさんのポストを全部確認してみましょうか。 全部のポストを取り出すのではなく、olaさんのポストだけを取り出したい場合は、@<tt>{Post.objects.all()} の @<tt>{all} を @<tt>{filter} に変更します。 取り出されるブログポストが満たす条件を、カッコ()の中に指定します。 今回の例では、@<tt>{author} が @<tt>{me} と等しいという条件です。 Djangoでの表し方は、@<tt>{author=me} となります。 このようになりますね。


//emlist[command-line]{
>>> Post.objects.filter(author=me)
@<seqsplit>{<QuerySet [<Post: Sample title>, <Post: Post number 2>, <Post: My 3rd post!>, <Post: 4th title of post>]>}
//}


もしかすると @<tt>{title} フィールドに title という単語が含まれているポストだけを取り出したくなるかもしれませんね。


//emlist[command-line]{
>>> Post.objects.filter(title__contains='title')
<QuerySet [<Post: Sample title>, <Post: 4th title of post>]>
//}

//quote{
@<strong>{Note} @<tt>{title} と @<tt>{contains} の間に、アンダーバー (@<tt>{_}) が2個続いていますが、 これはDjangoのORMの構文です。フィールド名のtitleと、照合タイプのcontainsを、2つのアンダーバーで連結させています。 もしアンダーバーが1個だけだと、title@<b>{contains というフィールド名だと判断されてしまい、エラーになります。("FieldError: Cannot resolve keyword title}contains")

//}


また、公開済みの全ポストを取り出すことも出来ます。それには、@<tt>{published_date} が現在以前の全ポストを取り出します。


//emlist[command-line]{
>>> from django.utils import timezone
>>> Post.objects.filter(published_date__lte=timezone.now())
<QuerySet []>
//}


そうでした、残念なことに、コンソールから追加したポストはまだ公開されていませんね。じゃあ、ポストを公開してみるとしましょう。まず公開するポストを決めましょう。


//emlist[command-line]{
>>> post = Post.objects.get(title="Sample title")
//}


そして、@<tt>{publish} メソッドを呼び出します。


//emlist[command-line]{
>>> post.publish()
//}


じゃあ、もう一度公開済みのポストを取り出しましょう。(上方向キーを3回押せば、さっきのコマンドを呼び出せるでしょう。コマンドを表示出来たら、@<tt>{Enter} キーを押してみましょう)


//emlist[command-line]{
>>> Post.objects.filter(published_date__lte=timezone.now())
<QuerySet [<Post: Sample title>]>
//}

=== オブジェクトの並び替え


クエリセットは、オブジェクトのリストの並べ替えもやってくれます。試しに @<tt>{created_date} フィールドで並べ替えてみましょう。


//emlist[command-line]{
>>> Post.objects.order_by('created_date')
@<seqsplit>{<QuerySet [<Post: Sample title>, <Post: Post number 2>, <Post: My 3rd post!>, <Post: 4th title of post>]>}
//}


逆順、つまり新しく追加した順に並べ替えることも出来ます。それには、@<tt>{-}（ハイフン）を使います。


//emlist[command-line]{
>>> Post.objects.order_by('-created_date')
@<seqsplit>{<QuerySet [<Post: 4th title of post>,  <Post: My 3rd post!>, <Post: Post number 2>, <Post: Sample title>]>}
//}

=== クエリセットをつなげる


QuerySetsを @<strong>{つなげて} 組み合わせることも出来ます。


//emlist[command-line]{
@<seqsplit>{>>> Post.objects.filter(published_date__lte=timezone.now()).order_by('published_date')}
@<seqsplit>{<QuerySet [<Post: Post number 2>, <Post: My 3rd post!>, <Post: 4th title of post>, <Post: Sample title>]>}
//}


クエリセットをつなげるのは本当に強力です。つなげていくことでとても複雑なクエリも書くことが出来ます。



いいですね！次の章への準備は万端ですね！このプロンプトを閉じるには、以下のようにします。


//emlist[command-line]{
>>> exit()
$
//}
