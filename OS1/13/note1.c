int sw_user1 = 12;
int sw_user2 = 11;
int sw_user3 = 10;
int sw_user4 = 9;

int led_user1 = 8;
int led_user2 = 7;
int led_user3 = 6;
int led_user4 = 5;

int sw_reset = 4;

void setup()
{
    pinMode(sw_user1, INPUT);
    pinMode(sw_user2, INPUT);
    pinMode(sw_user3, INPUT);
    pinMode(sw_user4, INPUT);

    pinMode(sw_user1, OUTPUT);
    pinMode(sw_user2, OUTPUT);
    pinMode(sw_user3, OUTPUT);
    pinMode(sw_user4, OUTPUT);
    
    pinMode(sw_reset, INPUT);
}

void loop()
{
    
    while(digitalRead(sw_reset)) {
        if (!digitalRead(sw_user1) || !digitalRead(sw_user2) || !digitalRead(sw_user3) || !digitalRead(sw_user4)) {
            digitalWrite(led_user1, digitalRead(sw_user1)==LOW ? HIGH : LOW);
            digitalWrite(led_user2, digitalRead(sw_user2)==LOW ? HIGH : LOW);
            digitalWrite(led_user3, digitalRead(sw_user3)==LOW ? HIGH : LOW);
            digitalWrite(led_user4, digitalRead(sw_user4)==LOW ? HIGH : LOW);
    	}
    }

    digitalWrite(led_user1, LOW);
    digitalWrite(led_user2, LOW);
    digitalWrite(led_user3, LOW);
    digitalWrite(led_user4, LOW);
}