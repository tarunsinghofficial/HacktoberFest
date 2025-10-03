import React from "react";
import styles from "./toggleButton.module.css";
import { hotelListingDataRequest } from "../../redux/authentication/actions";
import { connect } from "react-redux";

function toggleButton(props) {
  console.log(props);
  let { handleToggle } = props;
  return (
    <>
      <input type="checkbox" id="switch" className={styles.checkbox} onChange={() => handleToggle()} />
      <label for="switch" className={`${styles.toggle} + m-0`}></label>
    </>
  );
}

const mapStateToProps = (state) => ({
  hotelData: state.auth.hotelListData,
});

const mapDispatchToProps = (dispatch) => ({
  hotelListingDataRequest: (payload) => dispatch(hotelListingDataRequest(payload)),
});

export default connect(mapStateToProps, mapDispatchToProps)(toggleButton);
