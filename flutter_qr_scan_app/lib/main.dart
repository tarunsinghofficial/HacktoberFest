import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:qr_app/screens/home.dart';
import 'package:qr_app/screens/webView/webView.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return GetMaterialApp(
      title: 'Material App',
      home: OpenInWeb(link:'https://google.com',),
    );
  }
}
