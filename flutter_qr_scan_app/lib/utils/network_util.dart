import 'dart:convert';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:get/get.dart';
import 'package:http/http.dart' as http;
import 'constants.dart';

class NetworkUtil{
  static Future<Map<String,dynamic>?> request({required String apiEndpoint,Map? body,required String method,BuildContext? context}) async {
      String url = apiEndpoint;
      try{
        if(method=='Post'){
          final response = await http.post(Uri.parse(url),body:body,headers: {'authorization':'_localData.token'});
          return checkForError(response);
        }else{
          final response = await http.get(Uri.parse(url),headers: {'authorization':'_localData.token'});
          return checkForError(response);
        }
      }catch(e){
        Get.snackbar('Failed','Something Went Wrong',colorText: Colors.white,backgroundColor: primaryColor);
        return null;
      }
  }

  static Map<String , dynamic>? checkForError(http.Response response){
    if(response.statusCode==200||response.statusCode==400){
      var data = json.decode(response.body);
      switch(data['code']){
        case 0 :
          Get.snackbar('Failed', data['message']??'Something Went Wrong',colorText: Colors.white,backgroundColor: primaryColor);
          print(data);
          return data;
        case 1 :
          if(data['message']!=null)
            Get.snackbar('Success', data['message'],colorText: Colors.white,backgroundColor: primaryColor);
          return data;
        case 3 :
          print('failed');
          Get.snackbar('Failed', data['message']??'Something Went Wrong',colorText: Colors.white,backgroundColor: primaryColor);
          return null;
        default:
          return data;
      }
    }else{
      Get.snackbar('Failed','Something Went Wrong',colorText: Colors.white,backgroundColor: primaryColor);
      return null;
    }
  }
}