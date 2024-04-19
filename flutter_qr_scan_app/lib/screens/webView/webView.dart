import 'dart:async';
import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:qr_app/screens/signature/signature_pad.dart';
import 'package:webview_flutter/webview_flutter.dart';

class OpenInWeb extends StatefulWidget {
  final String link;
  const OpenInWeb({Key? key, required this.link}) : super(key: key);

  @override
  _OpenInWebState createState() => _OpenInWebState();
}

class _OpenInWebState extends State<OpenInWeb> {
  late WebViewController _controller;
  final Completer<WebViewController> _controllerCompleter =
  Completer<WebViewController>();

  @override
  Widget build(BuildContext context) {
    return WillPopScope(
      onWillPop: () => _goBack(context),
      child: Scaffold(
        body: SafeArea(
          child: Column(
            children: [
              Expanded(
                child: WebView(
                  initialUrl: widget.link,
                  javascriptMode: JavascriptMode.unrestricted,
                  onWebViewCreated: (WebViewController webViewController) {
                    _controllerCompleter.future.then((value) => _controller = value);
                    _controllerCompleter.complete(webViewController);
                  },
                ),
              ),
              Container(
                height:100,
                child: Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: <Widget>[
                    RaisedButton(
                        onPressed: (){
                           Get.to(()=>SignaturePad());
                        },
                        child: Text('Digital Signature'),
                    ),
                    RaisedButton(
                        onPressed: (){},
                        child: Text('E-Sign'),
                    )
                  ],
                ),
              )
            ],
          ),
        ),
      ),
    );
  }

  Future<bool> _goBack(BuildContext context) async {
    if (await _controller.canGoBack()) {
      _controller.goBack();
      return Future.value(false);
    } else {
      Navigator.of(context).pop();
      return Future.value(true);
    }
  }
}
