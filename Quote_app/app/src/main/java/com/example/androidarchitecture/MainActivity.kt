package com.example.androidarchitecture

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.TextView
import androidx.databinding.DataBindingUtil
import androidx.lifecycle.ViewModelProvider
import com.example.androidarchitecture.components.MainViewModel
import com.example.androidarchitecture.components.MainViewModelFactory
import com.example.androidarchitecture.components.Observer
import com.example.androidarchitecture.components.Quote
import com.example.androidarchitecture.databinding.ActivityMainBinding
import com.google.android.material.floatingactionbutton.FloatingActionButton

class MainActivity : AppCompatActivity() {

    lateinit var viewModel : MainViewModel
    lateinit var binding: ActivityMainBinding

//    private val quoteText : TextView
//        get() = findViewById(R.id.quoteText)
//
//    private val quoteAuthor : TextView
//        get() = findViewById(R.id.quoteAuthor)

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = DataBindingUtil.setContentView(this,R.layout.activity_main)

//        lifecycle.addObserver(Observer())

        viewModel = ViewModelProvider(this,MainViewModelFactory(application))[MainViewModel::class.java]
        //make a observer
        binding.quote = viewModel.getQuote()
        viewModel.quoteLiveData.observe(this, {
            binding.quote = it
        })


//        setQuote(viewModel.getQuote())
        binding.mainViewModel = viewModel
        binding.lifecycleOwner = this
    }

//    fun setQuote(quote: Quote) {
//        quoteText.text = quote.text
//        quoteAuthor.text = quote.author
//    }
//
//    fun onNext(view : View) {
//        setQuote(viewModel.nextQuote())
//        binding.quote = viewModel.nextQuote()
//    }
//
//    fun onPrevious(view : View) {
//        setQuote(viewModel.previousQuote())
//        binding.quote = viewModel.previousQuote()
//    }

    fun onShare(view : View) {
        val intent = Intent(Intent.ACTION_SEND)
        intent.type = "text/plain"
        intent.putExtra(Intent.EXTRA_TEXT,viewModel.getQuote().text)
        startActivity(intent)
    }

}