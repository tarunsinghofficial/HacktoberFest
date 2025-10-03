import React, { Component } from "react";
import styles from "./Form.module.css";
import { connect } from "react-redux";
import { loginRequestWithOtp, loginRequestWithOauth } from "../../redux/authentication/actions";
import GoogleLogin from "react-google-login";
import {Redirect,Link} from "react-router-dom"

let pattern = {
  mobile: /^\d{10}$/,
};

class LoginWithOTP extends Component {
  constructor(props) {
    super(props);
    this.state = {
      mobile: "",
      isMobileValid: false,
    };
  }

  // for google oauth login
  googleResponse = (googleUser) => {

    const {accessToken} = googleUser
    const{name,email} = googleUser.profileObj
    console.log(accessToken,name,email)

    const value = {
      name,
      email,
      provider:"google",
      access_token:accessToken
    }

     if (value) {
     //console.log(value)
       this.props.loginRequestWithOauth(value);
     }
  };

  handleChange = (e) => {
    this.setState(
      {
        [e.target.name]: e.target.value,
      }
      
    );
  };

  validate(pattern, value) {
    if (pattern.test(value)) {
      return true;
    } else {
      return false;
    }
  }

  handleLoginWithOtp = (e) => {
    e.preventDefault();
    const { mobile, isMobileValid } = this.state;
    if (!mobile) {
      this.setState({ isMobileValid: true });
      return;
    }
    
    let mobileValidValue = this.validate(pattern.mobile, mobile);
    if (mobileValidValue) {
   
      this.props.loginRequestWithOtp({mobile});
    } else {
      this.setState({ isMobileValid: true });
      return 
    }
  };

  render() {

    

    const { mobile, handleChange, isMobileValid } = this;
    const {showLoginWithPassword,token,user,otpGenerate} = this.props
   // console.log(token,user)
    if (token ) {
      localStorage.setItem("jwt", token);
      localStorage.setItem("data", JSON.stringify(user));
      return <Redirect to="/" />
    }
     if (otpGenerate ) {
      return <Redirect to="/otpverify" />
    }
    
    return (
      <form id={styles.signupform}>
        <div className="form-group">
          <div id={styles.loginHeader}> Login / Signup</div>
          <label for="exampleInputEmail1"> Please enter your phone number to continue</label>
          <input type="number" name="mobile" value={mobile} onChange={handleChange} className="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" />
          <small className={isMobileValid ? "d-block" : "d-none"}>not an valid email</small>
        </div>

        <button id={styles.button} type="submit" onClick={this.handleLoginWithOtp} className="btn btn-primary">
          Verify Number
        </button>
        <div id={styles.formFooter}>
          Prefer to Proceed with OTP instead?{" "}
          <Link className="text-danger" to="/login">
            Click here
          </Link>
          <div className="border-bottom w-100 mt-4 text-center">
            Or sing in as
          </div>
          <div className="text-center mt-4">
              <GoogleLogin
              clientId={"412804596146-clkr9mtigjj70d3atl49nctpai3q7bb7.apps.googleusercontent.com"}
              onSuccess={this.googleResponse}
              onFailure={this.googleResponse}
              cookiePolicy="single_host_origin"
              uxMode="popup"
              isSignedIn={false}
            ></GoogleLogin>
          </div>
        </div>
        
      </form>
    );
  }
}

const mapStateToProps = (state) => ({
  
  otpGenerate: state.auth.otpGenarate,
  user:state.auth.user,
  token:state.auth.token

});

const mapDispatchToProps = (dispatch) => ({
  loginRequestWithOtp: (payload) => dispatch(loginRequestWithOtp(payload)),
  loginRequestWithOauth: (payload) => dispatch(loginRequestWithOauth(payload)),
});

export default connect(mapStateToProps, mapDispatchToProps)(LoginWithOTP);
