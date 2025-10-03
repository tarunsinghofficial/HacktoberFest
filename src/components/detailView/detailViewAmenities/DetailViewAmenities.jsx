import React, { Component } from "react";
import styles from "./DetailViewAmenities.module.css";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
// import { faFan, faWifi, faBed } from "@fortawesome/free-solid-svg-icons";
import { faStar ,faCheckCircle, faFan,  faToilet, faPersonBooth, faMusic,faHandHoldingWater,faMoneyBillWave,faBreadSlice,faWifi,faFire, faHotTub, faBed,faCheese, faRestroom,faParking,faThermometerEmpty, faChair, faTv, faSoap, faBold, faBone, faDotCircle, faTags, faPen} from "@fortawesome/free-solid-svg-icons"
import {connect} from "react-redux"

 class DetailViewAmenities extends Component {

  constructor(props){
    super(props);
    this.state={
      showFontIcon:false
    }
  }

   
  findFontawesome=(ele)=>{
    let fa = [faStar,faPen,faTags ,faCheckCircle, faFan,  faToilet, faPersonBooth, faMusic,faHandHoldingWater,faMoneyBillWave,faBreadSlice,faWifi,faFire, faHotTub, faBed,faCheese, faRestroom,faParking,faThermometerEmpty, faChair, faTv, faSoap]
    switch(ele){
      case "faFan":
        return faFan
      case "faWifi":
        return faWifi
      case "faFire":
        return faFire
      case "faTv":
        return faTv
      case "faBreadSlice":
        return faBreadSlice
      case "faToilet":
        return faToilet
      case "faHotTub":
        return faHotTub
      case "faParking":
        return faParking
      case "faSoap":
        return faSoap
      case "faBed":
        return faBed
      case "faCheese":
        return faCheese
      case "faBed":
        return faBed
      case "faHandHoldingWater":
        return faHandHoldingWater
      case "faChair":
        return faChair
      case "faThermometerEmpty":
        return faThermometerEmpty
      case "faMoneyBillWave":
        return faMoneyBillWave
      case "faMusic":
        return faMusic
      case "faHandHoldingWater":
        return faHandHoldingWater
      case "faBone":
        return faBone
      case "faRestroom":
        return faRestroom
      case "faStar":
        return faStar
      case "faDoorClosed":
        return this.faDoorClosed
      case "faPen":
        return faPen
      case "faTags":
        return faTags
      case "faCheckCircle":
        return faCheckCircle
      case "faPersonBooth":
        return faPersonBooth
      default:
        return faDotCircle
    }
  }
   render() {
    let amenities = []
    let amenities2 = []
    const {entityData} = this.props
    const {showFontIcon}  =this.state
    const {findFontawesome} =  this
    console.log(entityData,"amenities")
    if(entityData){

       entityData.amenities.map(ele=>{
        if(ele.status){
          amenities2.push(ele)
        }
        if(amenities.length<6){
          amenities.push(ele)

        }

      })
    }
    console.log(amenities, typeof faFan)
    // let amenities = []
    // if(entityData){

    //    for (item of entityData.amenities[0]){
    //      console.log (item)
    //    }

    //    console.log(amenities)
    // }
    return (
      <div className="col-12 px-3 mt-5">
        <div>
          <div className="px-4" id={styles.heading}>
            Amenities
          </div>
          <div className="d-flex justify-content-around flex-wrap" id={styles.container}>
          {!showFontIcon && amenities && amenities.map((elem) => {
              console.log(elem);
              return (
                <div className="col-4">
                  <span>
                    <FontAwesomeIcon icon={findFontawesome(elem.frot_awsome)} color="#000" size="lg" />
                  </span>
                  <span>{elem.label}</span>
                </div>
              );
            })}
          {showFontIcon && amenities2 && amenities2.map((elem) => {
              console.log(elem);
              return (
                <div className="col-4">
                  <span>
                    <FontAwesomeIcon icon={findFontawesome(elem.frot_awsome)} color="#000" size="lg" />
                  </span>
                  <span>{elem.label}</span>
                </div>
              );
            })}
          </div>
          <div onClick={()=>this.setState({showFontIcon:!showFontIcon})} className=" mx-4 mt-3" id={styles.showMore}>
            {showFontIcon?"Show Less":"Show More"}
          </div>
        </div>
      </div>
    );
  }
}

const mapStateToProps = (state) => ({
  token: state.auth.token,
    user: state.auth.user,
    entityData: state.auth.entityData
});



export default connect(mapStateToProps, null)(DetailViewAmenities);