import React, { Component } from "react";
import styles from "./Form.module.css";
import { connect } from "react-redux";
import { loginRequestWithPassword, loginRequestWithOauth, changeSignupValue } from "../../redux/authentication/actions";
import GoogleLogin from "react-google-login";
import { Redirect, Link } from "react-router-dom";

let pattern = {
  username: /^[a-z\d]{5,12}$/i,
  name: /^[a-z]{5,12}$/i,
  password: /^[\w@-]{8,15}$/i,
  mobile: /^\d{10}$/,
  email: /^([a-z\d\.-]+)@([a-z\d-]+)\.([a-z]{2,6})(\.[a-z]{2,6})?$/i,
  //abc@example.com.in
};

class LoginWithPassword extends Component {
  constructor(props) {
    super(props);
    this.state = {
      mobile: "",
      password: "",
      isMobileValid: false,
      isPasswordValid: false,
      isMessage: false,
      messageText: "please enter all the fields",
    };
  }

  // for google oauth login
  googleResponse = (googleUser) => {
    const { accessToken } = googleUser;
    const { name, email } = googleUser.profileObj;
    console.log(accessToken, name, email);

    const value = {
      name,
      email,
      provider: "google",
      access_token: accessToken,
    };

    if (value) {
      this.props.loginRequestWithOauth(value);
    }
  };

  handleChange = (e) => {
    this.setState(
      {
        [e.target.name]: e.target.value,
      },
      () => console.log(this.state)
    );
  };

  validate(pattern, value) {
    if (pattern.test(value)) {
      return true;
    } else {
      return false;
    }
  }

  handleLoginWithPassword = (e) => {
    e.preventDefault();
    const { mobile, password, isMobileValid, isPasswordValid } = this.state;

    if (!mobile || !password) {
      this.setState({ isMessage: true });
      return;
    }
    let mobileValidValue = this.validate(pattern.mobile, mobile);
    let passwordValidValue = this.validate(pattern.password, password);

    if (!mobileValidValue) {
      return this.setState({ isMobileValid: true });
    }
    if (!passwordValidValue) {
      return this.setState({ isPasswordValid: true });
    }

    if (mobile && password) {
      let value = { mobile, password };
      console.log(value);
      this.props.loginRequestWithPassword(value);
    } else {
      return;
    }
  };

  render() {
    console.log(this.props);

    const { password, isPasswordValid, mobile, isMobileValid, isMessage, messageText } = this.state;
    const { token, showLoginWithOtp, user, isAuth } = this.props;

    if (isAuth) {
      //localStorage.setItem("jwt", token);
      //localStorage.setItem("data", JSON.stringify(user));
      return <Redirect to="/" />;
    }

    return (
      <form id={styles.signupform}>
        <div className="form-group">
          <div id={styles.loginHeader}> Login / Signup</div>

          {isMessage && <small className="d-block text-danger">{messageText}</small>}
          <label for="exampleInputEmail1"> Please enter your phone number to continue</label>
          <input type="number" name="mobile" value={mobile} onChange={this.handleChange} required className="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" />
          <small className={isMobileValid ? "d-block text-danger" : "d-none text-danger"}>mobile is not valid</small>
        </div>

        <div className="form-group">
          <label for="exampleInputPassword1">password</label>
          <input type="password" name="password" value={password} onChange={this.handleChange} required className="form-control" id="exampleInputPassword1" />
          <small className={isPasswordValid ? "d-block text-danger" : "d-none text-danger"}>mobile is not valid</small>
        </div>

        <button onClick={this.handleLoginWithPassword} id={styles.button} type="submit" className="btn btn-primary">
          Verify Number
        </button>

        <div id={styles.formFooter}>
          Prefer to Proceed with OTP instead?{" "}
          <Link className="text-danger" to="/loginotp">
            Click here
          </Link>
          <div className="border-bottom w-100 mt-4 text-center">Or sing in as</div>
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
  token: state.auth.token,
  user: state.auth.user,
  isAuth: state.auth.isAuth,
});

const mapDispatchToProps = (dispatch) => ({
  loginRequestWithPassword: (payload) => dispatch(loginRequestWithPassword(payload)),
  loginRequestWithOauth: (payload) => dispatch(loginRequestWithOauth(payload)),
  //changeSignupValue: (payload) => dispatch(changeSignupValue(payload)),
});

export default connect(mapStateToProps, mapDispatchToProps)(LoginWithPassword);
