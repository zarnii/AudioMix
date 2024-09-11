#define FIRST_SLIDER_PIN A0
#define SECOND_SLIDER_PIN A1
#define THRID_SLIDER_PIN A2
#define CALC_ERR 8
#define STOP_SYMBOL '$'

// MAX_VALUE 1023
uint16_t fs_prev_value = 0;
uint16_t ss_prev_value = 0;
uint16_t ts_prev_value = 0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  uint16_t fs_value = analogRead(FIRST_SLIDER_PIN);
  uint16_t fs_round_value = __round(fs_value, fs_prev_value, CALC_ERR);

  uint16_t ss_value = analogRead(SECOND_SLIDER_PIN);
  uint16_t ss_round_value = __round(ss_value, ss_prev_value, CALC_ERR);
  
  uint16_t ts_value = analogRead(THRID_SLIDER_PIN);
  uint16_t ts_round_value = __round(ts_value, ts_prev_value, CALC_ERR);
  
  

  if (fs_round_value != fs_prev_value)
  {
    fs_prev_value = fs_round_value;
    String str = "0-" + String(fs_value) + STOP_SYMBOL;
    Serial.write(str.c_str());
  }
  
  if (ss_round_value != ss_prev_value)
  {
    ss_prev_value = ss_round_value;
    String str = "1-" + String(ss_value) + STOP_SYMBOL;
    Serial.write(str.c_str());
  }
  
  if (ts_round_value != ts_prev_value)
  {
    ts_prev_value = ts_round_value;
    String str = "2-" + String(ts_value) + STOP_SYMBOL;
    Serial.write(str.c_str());
  }
  
  
}

uint16_t __round(uint16_t current_value, uint16_t prev_value, uint16_t calc_err)
{
  if (abs(current_value - prev_value) >= calc_err)
  {
    return current_value;
  }

  return prev_value;
}