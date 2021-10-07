package com.example.androidarchitecture.components

import android.widget.ImageView
import androidx.databinding.BindingAdapter
import com.bumptech.glide.Glide

@BindingAdapter("imageFromUrl")
fun ImageView.imageFromUrl(url : String) {
    Glide.with(this.context).load(url).into(this)
}