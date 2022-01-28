import { useState } from "react";
import { useForm } from "react-hook-form";
import emailjs from "emailjs-com";
import { ToastContainer, toast } from "react-toastify";
import "react-toastify/dist/ReactToastify.min.css";
//i have used email js to send email, you can use any email service as you wish . 
const ContactForm = () => {
  const { register, errors, handleSubmit, reset } = useForm();
  const [disabled, setDisabled] = useState(false);

  const toastifySuccess = () => {
    toast("Message sent!", {
      position: "top-right",
      autoClose: 5000,
      hideProgressBar: true,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: false,
      className: "submit-feedback success",
      toastId: "notifyToast",
    });
  };

  const toastifyEmailFailure = () => {
    toast("Enter Valid Email.", {
      position: "top-right",
      autoClose: 5000,
      hideProgressBar: true,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: false,
      className: "submit-feedback failure",
      toastId: "notifyToast",
    });
  };

  const toastifySubjectFailure = () => {
    toast("Enter Valid Subject.", {
      position: "top-right",
      autoClose: 5000,
      hideProgressBar: true,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: false,
      className: "submit-feedback failure",
      toastId: "notifyToast",
    });
  };

  const toastifyMessageFailure = () => {
    toast("Enter Valid Message.", {
      position: "top-right",
      autoClose: 5000,
      hideProgressBar: true,
      closeOnClick: true,
      pauseOnHover: true,
      draggable: false,
      className: "submit-feedback failure",
      toastId: "notifyToast",
    });
  };

  const emailFailure = () => {
    toastifyEmailFailure();
  };

  const subjectFailure = () => {
    toastifySubjectFailure();
  };
  const messageFailure = () => {
    toastifyMessageFailure();
  };

  const onSubmit = async (data) => {
    try {
      setDisabled(true);
      const templateParams = {
        name: data.name,
        email: data.email,
        subject: data.subject,
        message: data.message,
      };
      console.log("clicked");

      await emailjs.send(
        // to get the following details you need to create an account in emailjs 
        //add your email service from emailjs website Email Services
        "service_yourServiceName",
        
        //add your email template 
        "template_name",
        templateParams,
        
       //add you use id from emailjs. website 
        "User ID"
      );

      reset();
      toastifySuccess();
      setDisabled(false);
    } catch (e) {
      console.log(e);
    }
  };

  return (
    <div className="contactForm">
      <form
        className="contactForm_form"
        id="contact-form"
        onSubmit={handleSubmit(onSubmit)}
        noValidate>
        <div className="contactForm_main">
          <div className="contactForm_top">
            <input
              type="text"
              name="name"
              ref={register({
                required: {
                  value: true,
                  message: "",
                },
                maxLength: {
                  value: 30,
                  message: "Please use 30 characters or less",
                },
              })}
              className="contactForm_input "
              placeholder="Name"></input>
            {errors.name && (
              <span className="errorMessage">{errors.name.message}</span>
            )}

            <input
              type="email"
              name="email"
              ref={register({
                required: true,
                pattern: /^[a-zA-Z0-9.!#$%&’*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$/,
              })}
              className="contactForm_input"
              placeholder="Email address"></input>
            {errors.email && emailFailure()}
          </div>
          <div className="contactForm_sub">
            {" "}
            <input
              type="text"
              name="subject"
              ref={register({
                required: {
                  value: true,
                  message: "Please enter a subject",
                },
                maxLength: {
                  value: 75,
                  message: "Subject cannot exceed 75 characters",
                },
              })}
              className="contactForm_input"
              placeholder="Subject"></input>
            {errors.subject && subjectFailure()}
          </div>
          <div className="contactForm_area">
            {" "}
            <textarea
              rows={3}
              name="message"
              ref={register({
                required: true,
              })}
              className="contactForm_input"
              placeholder="Message"></textarea>
            {errors.message && messageFailure()}
          </div>
        </div>
        <button
          className="contactForm_button"
          disabled={disabled}
          type="submit">
          Submit
        </button>
      </form>

      <ToastContainer />
    </div>
  );
};

export default ContactForm;
