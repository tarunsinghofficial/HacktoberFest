import React, { Component } from "react";
import styles from "./DetailviewMeal.module.css";
import { faStar , faFan, faToilet, faPersonBooth, faMusic,faHandHoldingWater,faMoneyBillWave,faBreadSlice,faWifi,faFire, faHotTub, faBed,faCheese, faRestroom,faParking, faThermometerEmpty, faChair, faTv, faSoap} from "@fortawesome/free-solid-svg-icons"
import {hotelEntityDataRequest,hotelBillingDataRequest,hotelReviewDataRequest} from "../../../redux/authentication/actions"
import {connect} from "react-redux"

 class DetailViewMeal extends Component {

  
  componentDidMount=()=>{
    const {hotelEntityDataRequest,hotelBillingDataRequest,hotelReviewDataRequest} = this.props
    // hotelEntityDataRequest(10)
    //  hotelBillingDataRequest({
    //   hotel_id:"10",
    //   room_id:"1",
    //   check_in:"01/01/2020",
    //   check_out:"01/01/2020",
    //   no_of_guests:"2",
    //   no_of_rooms:"2",
    //   membership: true
    // })
    // hotelReviewDataRequest(10)
  }
  render() {
    return (
      <>
        <div className="px-4" id={styles.heading}>
          Choose your room
        </div>
        <div className="row m-0">
          {[
            { heading: "Breakfast", subHeading: "Continental & Indian menu", price: "1902" },
            { heading: "Breakfast", subHeading: "Continental & Indian menu", price: "1902" },
            { heading: "Breakfast", subHeading: "Continental & Indian menu", price: "1902" },
          ].map((elem) => {
            return (
              <div className="col-4 p-1">
                <div className="card mb-3 w-100">
                  <div className="row no-gutters p-2 align-items-center">
                    <div className="col-md-5 d-flex border p-1 rounded">
                      <img src="/images/bed.webp" id={styles.mealImage} className="card-img " alt="..." />
                    </div>
                    <div className="col-md-7 p-2">
                      <div className="card-body p-0">
                        <span className="card-title m-0" id={styles.subHeading}>
                          {elem.heading}
                        </span>

                        <div id={styles.menu}>{elem.subHeading}</div>
                        <div id={styles.mealPrice}>₹{elem.price}</div>
                      </div>
                    </div>

                    <div className="col-md-12 ">
                      <div className="p-2">
                        <button id={styles.selectButton}>Select</button>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            );
          })}
        </div>
      </>
    );
  }
}

const mapStateToProps = (state) => ({
  token: state.auth.token,
    user: state.auth.user,
    entityData: state.auth.entityData,
    review: state.auth.review,
    billingData:state.auth.billingData
});

const mapDispatchToProps = (dispatch) => ({
  hotelEntityDataRequest: (payload) => dispatch(hotelEntityDataRequest(payload)), 
  hotelBillingDataRequest: (payload) => dispatch(hotelBillingDataRequest(payload)), 
  hotelReviewDataRequest: (payload) => dispatch(hotelReviewDataRequest(payload)), 
});

export default connect(mapStateToProps, mapDispatchToProps)(DetailViewMeal);