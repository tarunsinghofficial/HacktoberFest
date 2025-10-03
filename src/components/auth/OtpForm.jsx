import React, { Component } from "react";
import styles from "./Form.module.css";
import {loginRequestWithOtpVerify} from "../../redux/authentication/actions"
import {connect} from "react-redux"
import {Redirect} from "react-router-dom"

class OtpForm extends Component {
  
  constructor(props){
    super(props);
    this.state = {
      digit1:"",
      digit2:"",
      digit3:"",
      digit4:"",
      isError:false
    }
  }
  handleChange=(e)=>{
    this.setState({
    [e.target.name]:e.target.value
    },()=>console.log("number ",this.state)
    )
    

  }

  handleVerifyOtp = (e)=>{
    e.preventDefault()
    const{digit1,digit2,digit3,digit4} = this.state
    console.log(digit1)
    const {mobileNumber} = this.props
    if(!digit1 || !digit2 || !digit3 || !digit4){
      return this.setState({isError:true})
    }
    
      let otp = [digit1,digit2,digit3,digit4].join("")
     if(otp.length !== 4){
       return this.setState({isError:true})
      } 
      console.log(otp, typeof otp)
      this.props.loginRequestWithOtpVerify({otp,mobile:"8500505795"})
    }
  render() {
    const {handleChange,handleVerifyOtp} = this
     const {isError,digit1,digit2,digit3,digit4} = this.state
     const {mobileNumber,token,user} = this.props
     if(token){
      return <Redirect to="/"/>
     }
   
    return (
      <form id={styles.signupform} onSubmit={handleVerifyOtp}>
        <div className="form-group">
          <div id={styles.loginHeader}>Share OTP</div>
          <label>We have sent a temporary passcode to you at +91-{mobileNumber}</label>
          <label className="text-danger">Use a different number</label>
          <div id={styles.codeHeader}>Enter your 4-digit passcode</div>
          <input type="number" name="digit1"  value={digit1} onChange={handleChange} id={styles.otp} maxLength="1" />
          <input type="number" name="digit2"  value={digit2} onChange={handleChange} id={styles.otp} maxLength="1" />
          <input type="number" name="digit3"  value={digit3} onChange={handleChange} id={styles.otp} maxLength="1" />
          <input type="number" name="digit4"  value={digit4} onChange={handleChange} id={styles.otp} maxLength="1" />
        </div>
        {
          isError && <small className="text-danger">please enter valid 4 digit otp</small>
        }

        <button  id={styles.button} type="submit" className="btn btn-primary">
          Submit
        </button>
        <div id={styles.formFooter}>
          <span className="text-danger">Resend Code</span>{" "}
        </div>
      </form>
    );
  }
}


const mapStateToProps = (state) => ({
  mobileNumber : state.auth.mobileNumber,
    token: state.auth.token,
    user: state.auth.user,
});

const mapDispatchToProps = (dispatch) => ({
  loginRequestWithOtpVerify: (payload) => dispatch(loginRequestWithOtpVerify(payload)),
});

export default connect(mapStateToProps, mapDispatchToProps)(OtpForm);
