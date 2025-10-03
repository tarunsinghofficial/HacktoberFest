import React, { Component } from "react";
import styles from "./Form.module.css";
import { connect } from "react-redux";
import { signupRequest,hotelListingDataRequest,changeSignupValue } from "../../redux/authentication/actions";
import {Redirect,Link} from "react-router-dom"

let pattern = {
  username: /^[a-z\d]{5,20}$/i,
  name: /^[a-z]{5,20}$/i,
  password: /^[\w@-]{8,20}$/i,
  mobile: /^\d{10}$/,
  email: /^([a-z\d\.-]+)@([a-z\d-]+)\.([a-z]{2,6})(\.[a-z]{2,6})?$/i,
  //abc@example.com.in
};

class SignUp extends Component {
  constructor(props) {
    super(props);
    this.state = {
      mobile: "",
      password: "",
      name: "",
      email: "",
      username: "",
      isMobileValid: false,
      isEmailValid: false,
      isUsernameValid: false,
      isNameValid: false,
      isPasswordValid: false,
      isMessage:false,
      messageText:"please enter all the fields"
    };
  }
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

  handleSignup = (e) => {
    e.preventDefault();

    
    const { signupRequest } = this.props;
    const { mobile, password, name, email, username } = this.state;

    if (!mobile || !name || !username || !email || !password) {
      this.setState({isMessage:true})
      return;
    }
    let mobileValidValue = this.validate(pattern.mobile, mobile);
    let emailValidValue = this.validate(pattern.email, email);
    let nameVaildValue = this.validate(pattern.name, name);
    let usernameValidValue = this.validate(pattern.username, username);
    let passwordValidValue = this.validate(pattern.password, password);

    if(!mobileValidValue){
     return this.setState({isMobileValid:true})
    }
    if(!passwordValidValue){
     return this.setState({isPasswordValid:true})
    }
    if(!nameVaildValue){
     return this.setState({isNameValid:true})
    }
    if(!emailValidValue){
     return this.setState({isEmailValid:true})
    }
    if(!usernameValidValue){
     return this.setState({isUsernameValid:true})
    }

    if (mobile && password && username && name && email) {
      let value = { mobile, password, name, email, username };
      console.log(value);
      this.props.signupRequest(value);
    } else {
      return;
    }
  };

  changeValue= ()=>{
      this.props.changeSignupValue(false)
      this.props.history.push("/")
  }

  render() {
    const { name, email, password, mobile, username, isNameValid, isMobileValid,
       isEmailValid, isPasswordValid, isUsernameValid, isMessage,messageText } = this.state;
    const { handleChange, handleSignup, changeValue } = this
    const {isSignUp} = this.props

    if(isSignUp){
      changeValue()

    }

    return (
      <form id={styles.signupform}>
        <div className="form-group">
           {isMessage && <small className="d-block text-danger">{messageText}</small>}

          <label for="exampleInputEmail1">Name</label>
          <input type="text" name="name" value={name} onChange={handleChange} className="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" />
          <small className={isNameValid ? "d-block text-danger" : "d-none text-danger"}>not valid name</small>
        </div>
        <div className="form-group">
          <label for="exampleInputPassword1">Username</label>
          <input type="text" name="username" value={username} onChange={handleChange} className="form-control" id="exampleInputPassword1" />
          <small className={isUsernameValid ? "d-block text-danger" : "d-none text-danger"}>not valid username</small>
        </div>
        <div className="form-group">
          <label for="exampleInputEmail1">Email address</label>
          <input type="email" name="email" value={email} onChange={handleChange} className="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" />
          <small className={isEmailValid ? "d-block text-danger" : "d-none text-danger"}>not an valid email</small>
        </div>
        <div className="form-group">
          <label for="exampleInputPassword1">Create a password</label>
          <input type="password" name="password" value={password} onChange={handleChange} className="form-control" id="exampleInputPassword1" />
          <small className={isPasswordValid ? "d-block text-danger" : "d-none text-danger"}>not valid password</small>
        </div>
        <div className="form-group">
          <label for="exampleInputPassword1">Enter 10 digit mobile</label>
          <input type="number" name="mobile" value={mobile} onChange={handleChange} className="form-control" id="exampleInputPassword1" />
          <small className={isMobileValid ? "d-block text-danger" : "d-none text-danger"}>not valid mobile</small>
        </div>

        <button id={styles.button} type="submit" className="btn btn-primary" onClick={handleSignup}>
          signup
        </button>
        Prefer to Proceed with OTP login instead?{" "}
          <Link className="text-danger" to="/login">
            Click here
          </Link>{" "}
      </form>
    );
  }
}

const mapStateToProps = (state) => ({
  isSignUp: state.auth.isSignup,
});

const mapDispatchToProps = (dispatch) => ({
  signupRequest: (payload) => dispatch(signupRequest(payload)),
  changeSignupValue: (payload) => dispatch(changeSignupValue(payload)),
});

export default connect(mapStateToProps, mapDispatchToProps)(SignUp);
