package com.example.kotlinapplication

import android.app.DownloadManager
import android.content.Intent
import android.graphics.drawable.Drawable
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.Button
import android.widget.ImageView
import android.widget.ProgressBar
import android.widget.TextView
import com.android.volley.Request
import com.android.volley.Response
import com.android.volley.toolbox.JsonObjectRequest
import com.android.volley.toolbox.JsonRequest
import com.android.volley.toolbox.StringRequest
import com.android.volley.toolbox.Volley
import com.bumptech.glide.Glide
import com.bumptech.glide.load.DataSource
import com.bumptech.glide.load.engine.GlideException
import com.bumptech.glide.request.RequestListener
import com.bumptech.glide.request.target.Target
import org.json.JSONObject

class MainActivity : AppCompatActivity() {
    lateinit var memeImageView: ImageView
    lateinit var shareBtn : Button
    lateinit var nextBtn : Button
    lateinit var progressBar: ProgressBar
    var apiUrl : String = "https://meme-api.herokuapp.com/gimme"
    lateinit var url : String

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        memeImageView = findViewById(R.id.memeImage)
        shareBtn = findViewById(R.id.shareBtn)
        nextBtn = findViewById(R.id.nextBtn)
        progressBar = findViewById(R.id.progressBar)

        loadData()

        nextBtn.setOnClickListener(View.OnClickListener {
            nextBtnFunc()
        })

        shareBtn.setOnClickListener(View.OnClickListener {
            shareBtnFunc()
        })

    }

    private fun shareBtnFunc() {
        val intent = Intent(Intent.ACTION_SEND)
        intent.type = "text/plain"
        intent.putExtra(Intent.EXTRA_TEXT,"Hey checkout this meme $url")
        val chooser = Intent.createChooser(intent,"Share this meme using.....")
        startActivity(chooser)
    }

    private fun nextBtnFunc() {
        loadData()
    }

    fun loadData() {
        progressBar.visibility = View.VISIBLE
        var queue = Volley.newRequestQueue(this)
        var flag : Boolean = false
        val jsonRequest = JsonObjectRequest(Request.Method.GET,apiUrl,null, { response ->
            url = response.getString("url")
            Log.e("volley_call",response.getString("url"))
            Glide.with(this).load(url).listener(object:RequestListener<Drawable> {
                override fun onLoadFailed(
                    e: GlideException?,
                    model: Any?,
                    target: Target<Drawable>?,
                    isFirstResource: Boolean
                ): Boolean {
                    progressBar.visibility = View.GONE
                    return false
                }

                override fun onResourceReady(
                    resource: Drawable?,
                    model: Any?,
                    target: Target<Drawable>?,
                    dataSource: DataSource?,
                    isFirstResource: Boolean
                ): Boolean {
                    progressBar.visibility = View.GONE
                    return false
                }
            }).into(memeImageView)
        },
            {
                progressBar.visibility = View.GONE
                Glide.with(this).load(R.drawable.middle).into(memeImageView)
            })
        queue.add(jsonRequest)
    }
}