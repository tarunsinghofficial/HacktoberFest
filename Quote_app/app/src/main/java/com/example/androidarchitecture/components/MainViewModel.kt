package com.example.androidarchitecture.components

import android.content.Context
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.google.gson.Gson

class MainViewModel(val context: Context) : ViewModel() {
    private var quoteList : Array<Quote> = emptyArray()
    private var index = 0
    private var liveDataObjects = MutableLiveData(Quote("Nothing","Nothing"))

    val quoteLiveData : LiveData<Quote>
        get() = liveDataObjects

    init {
        quoteList = loadQuoteFromAssets()
        liveDataObjects = MutableLiveData(getQuote())
    }


    private fun loadQuoteFromAssets(): Array<Quote> {
        val inputStream = context.assets.open("quotes.json")
        val size : Int = inputStream.available()
        val buffer = ByteArray(size)
        inputStream.read(buffer)
        inputStream.close()
        val json = String(buffer, Charsets.UTF_8)
        val gson = Gson()
        return gson.fromJson(json, Array<Quote>::class.java)
    }

    fun getQuote() = quoteList[index]

    fun nextQuote() {
        liveDataObjects.value = quoteList[++index]
    }

    fun previousQuote() {
        liveDataObjects.value = quoteList[--index]
    }
}