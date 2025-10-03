import React, { Component } from "react";
import FacebookLogin from "react-facebook-login";

class FacebookOauth extends Component {
  facebookResponse = () => {};

  render() {
    return (
      <div>
        <FacebookLogin
          appId={process.env.REACT_APP_FACEBOOK_APP_ID}
          autoLoad={false}
          fields="name,email,picture"
          callback={this.facebookResponse}
        />
      </div>
    );
  }
}

export default FacebookOauth;
