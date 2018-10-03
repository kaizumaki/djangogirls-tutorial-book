
= インターネットのしくみ

//quote{
家で１人でこのチャプターに挑戦している方へ：このチャプターは、動画（英語）もあるので参考にしてください。 @<href>{https://www.youtube.com/watch?v=oM9yAA09wdc,How the Internet Works}



この章は、ジェシカ・マッケラー（http://web.mit.edu/jesstess/www/）による「インターネットの仕組み」を参照しています。

//}


私達は、毎日インターネットを使っています。でも、ブラウザのアドレス欄に https://djangogirls.org のようなアドレスを入力して @<tt>{Enter} キーを押すと何が起こるか、あなたは実際に知っていますか？



まず最初に理解する必要があるのは、Webサイトはハードディスクに保存された沢山のファイルであるということです。 あなたが自分のパソコンのハードディスクに動画や音楽や画像を保存しているのと同じということです。 しかし、Webサイトは動画や音楽、写真のようなデータとは違って、HTMLというコンピュータのコードを持っているのです。



もし、あなたがプログラミングに精通していなかったら、最初はHTMLも難しく感じるでしょう。でも、あなたがよく使うWebブラウザ（ChromeやSafariやFirefox等々）はHTMLのコードが大好きです。 Webブラウザはこのコードがわかるようになっていて、コードの指示に従います。そして、あなたのウェブサイトのファイルをあなたが望む方法で表示するのです。



あなたのパソコンへファイルを保存するのと同じで、私達はHTMLをハードディスクに保存する必要があります。 インターネットの場合、@<b>{サーバー} と呼ばれるパワフルなコンピュータを使い、そのハードディスクに保存します。 サーバーの主な目的は、データを保存したり、データを供給したりすることなので、サーバーは画面やマウス、キーボードを持っていません。 サーバーはデータを供給する（@<b>{サーブ} する）役割を持っているので、@<b>{サーバー} と呼ばれるのです。



はい、では、どのようにインターネットが見えるかを知りたいですよね？



私たちは絵を描いてみました。



//image[internet_1][]{
//}




上記の絵は混乱しているように見えますよね？ 接続されたマシン（@<b>{サーバー}）のネットワークは実際こんな感じです。 数十万台のマシン！ 世界中はりめぐらされたケーブル！ Submarine Cable MapのWebサイト (http://submarinecablemap.com) にアクセスすれば、ネットの複雑さを知ることができます。 ここにウェブサイトからのスクリーンショットがあります：



//image[internet_3][]{
//}




すばらしいですね。 でも、インターネットに接続されているすべてのマシンとマシンの間にワイヤを置くことは不可能です。 したがって、マシン（例えば http://djangogirls.org が保存されているマシン）に到達するためには、多くの異なるマシンを介してリクエストを渡す必要があります。



こんな感じですね。



//image[internet_2][]{
//}




あなたが http://djangogirls.org と入力すると、「親愛なるDjango Girlsへ。私はdjangogirls.orgのWebサイトが見たいです。それを私に送ってください」とリクエスト（手紙）を送ることになります。



あなたの手紙（リクエスト）は、まずあなたの一番近くの郵便局にいきますよね。 そしてそこから、もう少し宛先に近い別の郵便局に行き、またそこからもう少し近い郵便局に行って・・そしてあなたの目的地まで届きます。 特別なことが一つあります。同じ宛先に多くの手紙（@<b>{データパケット}）を送ると、まったく別の郵便局（@<b>{ルーター}）を通過して届く可能性があるということです。 届くまでの道順は、郵便局ごとの配送方法次第です。



//image[internet_4][]{
//}




このように動作しています。あなたはメッセージを送信し、何らかの応答を期待します。 紙とペンではなく、データのバイトを使用しますが、アイデアは同じです！



市町村名、郵便番号、国名の住所の代わりに、IPアドレスを使用します。 お使いのコンピュータは、まず djangogirls.org をIPアドレスに変換するようにDNS（Domain Name System）に依頼します。 あなたが連絡したい人の名前を探し、電話番号と住所を見つけることができる昔ながらの電話帳のようなものです。



手紙を送るときには、住所、切手など、正しく配送される特定の機能が必要ですよね。 また、受信者が理解できる言語も使用している必要がありますよね？ Webサイトを表示するために送信する @<b>{データパケット} についても同様です。 HTTP（Hypertext Transfer Protocol）というプロトコルを使用します。（プロトコルとは正しく配送されるための機能や、使う言語などについての取り決めのことです）



だから、基本的に、あなたがWebサイトを持つなら、@<b>{サーバー}（マシン）が必要です。 @<b>{サーバー} は @<b>{リクエスト} を（手紙で）受け取ると、Webサイトを（別の手紙で）返します。



これはDjangoチュートリアルですから、Djangoが何をしているのか知りたいでしょう？ あなたが返事を返す時、 いつもみんなに同じ返事を返したいわけではなく、 リクエストを送った人それぞれにパーソナライズされた返事を返した方がよいこともありますよね？ Djangoはパーソナライズされた面白い手紙を作るのに役立ちます。 :)



インターネットの話は以上です！さあ、いよいよあなたのブログサイトを作成する時間です！

