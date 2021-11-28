document.addEventListener('DOMContentLoaded', calculateLong());
document.addEventListener('DOMContentLoaded', showLong());

function calculateLong() {

  let size = parseFloat(document.getElementById('size').value);
  let risk = parseFloat(document.getElementById('risk').value);
  let entry = parseFloat(document.getElementById('entry').value);
  let stoploss = parseFloat(document.getElementById('stoploss').value);
  let target1 = parseFloat(document.getElementById('target1').value);
  let target2 = parseFloat(document.getElementById('target2').value);
  let target3 = parseFloat(document.getElementById('target3').value);

  risk_percent = (risk/100)*size
  document.getElementById('amtOnRisk').innerHTML = (risk_percent).toFixed(4);

  pos = risk_percent/(entry-stoploss)
  document.getElementById('optimumPositionSize').innerHTML = (pos).toFixed(4);

  document.getElementById('positionAmt').innerHTML = (pos*entry).toFixed(4);

  document.getElementById('amtAftStoploss').innerHTML = (size-risk_percent).toFixed(4);

  document.getElementById('amtAftTarget1').innerHTML = (pos*target1).toFixed(4);
  document.getElementById('NetAmtAftTarget1').innerHTML = (pos*target1 - pos*entry).toFixed(4);

  if(target2>0){
    document.getElementById('NetAmtAftTarget2').innerHTML = (pos*target2 - pos*entry).toFixed(4);
    document.getElementById('amtAftTarget2').innerHTML = (pos*target2).toFixed(4);
  }else{
    document.getElementById('NetAmtAftTarget2').innerHTML = 0;
    document.getElementById('amtAftTarget2').innerHTML = 0;
  }

  if(target3>0){
    document.getElementById('NetAmtAftTarget3').innerHTML = (pos*target3 - pos*entry).toFixed(4);
    document.getElementById('amtAftTarget3').innerHTML = (pos*target3).toFixed(4);
  }else{
    document.getElementById('NetAmtAftTarget3').innerHTML = 0;
    document.getElementById('amtAftTarget3').innerHTML = 0;
  }
}

function calculateShort() {
  let size = parseFloat(document.getElementById('size_short').value);
  let risk = parseFloat(document.getElementById('risk_short').value);
  let entry = parseFloat(document.getElementById('entry_short').value);
  let stoploss = parseFloat(document.getElementById('stoploss_short').value);
  let target1 = parseFloat(document.getElementById('target1_short').value);
  let target2 = parseFloat(document.getElementById('target2_short').value);
  let target3 = parseFloat(document.getElementById('target3_short').value);

  risk_percent = (risk/100)*size
  document.getElementById('amtOnRisk_short').innerHTML = (risk_percent).toFixed(4);

  pos = risk_percent/(stoploss-entry)
  document.getElementById('optimumPositionSize_short').innerHTML = (pos).toFixed(4);

  pos_amt = pos*entry
  document.getElementById('positionAmt_short').innerHTML = (pos_amt).toFixed(4);

  document.getElementById('amtAftStoploss_short').innerHTML = (size-risk_percent).toFixed(4);

  document.getElementById('amtAftTarget1_short').innerHTML = ((((entry-target1)/entry)*pos_amt) + pos_amt).toFixed(4);
  document.getElementById('NetAmtAftTarget1_short').innerHTML = (pos*entry - pos*target1).toFixed(4);

  if(target2>0){
    document.getElementById('amtAftTarget2_short').innerHTML = ((((entry-target2)/entry)*pos_amt) + pos_amt).toFixed(4);
    document.getElementById('NetAmtAftTarget2_short').innerHTML = (pos*entry - pos*target2).toFixed(4);
  }else{
    document.getElementById('amtAftTarget2_short').innerHTML = 0;
    document.getElementById('NetAmtAftTarget2_short').innerHTML = 0;
  }

  if(target3>0){
    document.getElementById('NetAmtAftTarget3_short').innerHTML = (pos*entry - pos*target3).toFixed(4);
    document.getElementById('amtAftTarget3_short').innerHTML = ((((entry-target3)/entry)*pos_amt) + pos_amt).toFixed(4);
  }else{
    document.getElementById('NetAmtAftTarget3_short').innerHTML = 0;
    document.getElementById('amtAftTarget3_short').innerHTML = 0;
  }
}


function showLong() {
  document.getElementById('short').style.display = 'none';
  document.getElementById('long').style.display = '';
}

function showShort() {
  document.getElementById('long').style.display = 'none';
  document.getElementById('short').style.display = '';
  calculateShort();
}
