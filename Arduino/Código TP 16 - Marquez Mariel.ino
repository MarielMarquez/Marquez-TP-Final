//Activación de los motores
#define motor1_activar 5  
#define motor2_activar 3  
#define motor4_activar 11  
#define motor3_activar 10  

//Motor 1
#define motor1_pin1 8 
#define motor1_pin2 7 

//Motor 2
#define motor2_pin1 2 
#define motor2_pin2 4 

//Motor 3
#define motor3_pin1 9
#define motor3_pin2 6 

//Motor 4
#define motor4_pin1 13
#define motor4_pin2 12

//Sensor de movimiento
#define Sensor_movimiento A0

//Interruptor deslizante
#define Config A1

char BT_recibido;

//////////////
void setup()
{
  //Pines
  configurarPines();
      
  //Monitor serial
  Serial.begin( 9800 );
  Serial.setTimeout( 50 );
  
}//Fin setup

//////////////
void loop()
{
  
  comunicacion();
  
  switch ( BT_recibido )
  {
    //Caso 1: Adelante
    case "w":
    	adelante();
    
    	break;
    
    //Caso 2: Atrás
    case 's':
		atras();	
    
    	break;
    
    //Caso 3: Derecha
    case 'd':
    	girarDerecha();
    
    	break;
    
    //Caso 4: Izquierda
    case 'a':
    	girarIzquierda();
    
    	break;
    
    //Caso 5: Derecha sobre si mismo
    case 'g':
    	girarDerecha_enSuEje();
    
    	break;
    
    //Caso 6: Izquierda sobre si mismo
    case 'h':
    	girarIzquierda_enSuEje();
    
    	break;
    
    //Caso 7: Frenado lento
    case 'l':
    	frenado_lento();
          
    	break;
    
    //Caso 8: Frenado rápido
    case 'r':
    	frenado_rapido();
          
    	break;
  }
  
}//Fin loop

/* -------------------- CONFIGURACIÓN -------------------- */

//////////////
void configurarPines();
{                     
  for( int pin = 2 ; pin <= 13  ; pin++ )
  {
    pinMode( pin , OUTPUT );
  }
  
  pinMode( Sensor_movimiento , INPUT );
  
}//Fin configurarPines

//////////////
bool configuracionBT()
{
  if( digitalRead( Config ) )
  {
      if( BT.available() )
      {
        Serial.write( BT.read() ) ; 
      }
      if( Serial.available() )
      {
        BT.write( Serial.read() );
      }
    
    return true;
  } 
  
  return false;
  
}//Fin configuracionBT

/* -------------- MOVIMIENTOS BÁSICOS -------------- */

//////////////
void adelante();
{
  //LOW = 0
  //HIGH = 1
  
  //Motores 1 y 2
  
  String motor1_2[] = { motor1_activar ,  motor2_activar , motor1_pin1 , motor1_pin2 , motor2_pin1 , motor2_pin2 };
  int estado1_2[]   = {      255       ,        255      ,      1      ,      0      ,       1     ,       0     };
  
  
  for( int i = 0 ; i < sizeof( motor1_2 ) / 2 ; i++)
  {
    //Encender(pines "activar")
    analogWrite(  motor1_2[i],  estado1_2[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor1_2[i] , estado1_2[i] );  
  }
  
  //Motores 3 y 4
  
  String motor3_4[] = { motor3_activar ,  motor4_activar , motor3_pin1 , motor3_pin2 , motor4_pin1 , motor4_pin2 };
  int estado3_4[]   = {      255       ,        255      ,      1      ,      0      ,       1     ,       0     };
  
  for( int i = 0 ; i < sizeof( motor3_4 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor3_4[i],  estado3_4[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor3_4[i] , estado3_4[i] );  
  }
  
}//Fin adelante

//////////////
void atras();
{
  //LOW = 0
  //HIGH = 1
  
  //Motores 1 y 2
  
  String motor1_2[] = { motor1_activar ,  motor2_activar , motor1_pin1 , motor1_pin2 , motor2_pin1 , motor2_pin2 };
  int estado1_2[]   = {      255       ,        255      ,      0      ,      1      ,       0     ,       1     };
  
  for( int i = 0 ; i < sizeof( motor1_2 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor1_2[i],  estado1_2[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor1_2[i] , estado1_2[i] );  
  }
  
  //Motores 3 y 4
  
  String motor3_4[] = { motor3_activar ,  motor4_activar , motor3_pin1 , motor3_pin2 , motor4_pin1 , motor4_pin2 };
  int estado3_4[]   = {      255       ,        255      ,      0      ,      1      ,       0     ,       1     };
  
  for( int i = 0 ; i < sizeof( motor3_4 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor3_4[i],  estado3_4[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor3_4[i] , estado3_4[i] );  
  }
  
}//Fin atras
  
/* ------------------------ GIROS ------------------------ */

//////////////
void girarDerecha()
{
  //LOW = 0
  //HIGH = 1
  
  //Motores 1 y 2
  
  String motor1_2[] = { motor1_activar ,  motor2_activar , motor1_pin1 , motor1_pin2 , motor2_pin1 , motor2_pin2 };
  int estado1_2[]   = {      255       ,        255      ,      0      ,      1      ,       0     ,       0     };
                            
  for( int i = 0 ; i < sizeof( motor1_2 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor1_2[i],  estado1_2[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor1_2[i] , estado1_2[i] );  
  }
  
  //Motores 3 y 4
  
  String motor3_4[] = { motor3_activar ,  motor4_activar , motor3_pin1 , motor3_pin2 , motor4_pin1 , motor4_pin2 };
  int estado3_4[]   = {      255       ,        255      ,      0      ,      1      ,       0     ,       0     };
  
  for( int i = 0 ; i < sizeof( motor3_4 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor3_4[i],  estado3_4[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor3_4[i] , estado3_4[i] );  
  }
  
}//Fin girarDerecha

//////////////
void girarIzquierda()
{
  //LOW = 0
  //HIGH = 1
  
  //Motores 1 y 2
  
  String motor1_2[] = { motor1_activar ,  motor2_activar , motor1_pin1 , motor1_pin2 , motor2_pin1 , motor2_pin2 };
  int estado1_2[]   = {      255       ,        255      ,      0      ,      0     ,       0     ,       1    };
  
  for( int i = 0 ; i < sizeof( motor1_2 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor1_2[i],  estado1_2[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor1_2[i] , estado1_2[i] );  
  }
  
  //Motores 3 y 4
  
  String motor3_4[] = { motor3_activar ,  motor4_activar , motor3_pin1 , motor3_pin2 , motor4_pin1 , motor4_pin2 };
  int estado3_4[]   = {      255       ,        255      ,      0      ,      0     ,       0     ,       1    };
  
  for( int i = 0 ; i < sizeof( motor3_4 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor3_4[i],  estado3_4[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor3_4[i] , estado3_4[i] );  
  } 
  
}//Fin girarIzquierda

//////////////
void girarDerecha_enSuEje()
{
  //LOW = 0
  //HIGH = 1
  
  //Motores 1 y 2
  
  String motor1_2[] = { motor1_activar ,  motor2_activar , motor1_pin1 , motor1_pin2 , motor2_pin1 , motor2_pin2 };
  int estado1_2[]   = {      255       ,        255      ,      1      ,      0     ,       0     ,       1    };
  
  for( int i = 0 ; i < sizeof( motor1_2 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor1_2[i],  estado1_2[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor1_2[i] , estado1_2[i] );  
  }
  
  //Motores 3 y 4
  
  String motor3_4[] = { motor3_activar ,  motor4_activar , motor3_pin1 , motor3_pin2 , motor4_pin1 , motor4_pin2 };
  int estado3_4[]   = {      255       ,        255      ,      1      ,      0     ,       0     ,       1    };
  
  for( int i = 0 ; i < sizeof( motor3_4 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor3_4[i],  estado3_4[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor3_4[i] , estado3_4[i] );  
  } 
}

//////////////
void girarIzquierda_enSuEje()
{
  //LOW = 0
  //HIGH = 1
  
  //Motores 1 y 2
  
  String motor1_2[] = { motor1_activar ,  motor2_activar , motor1_pin1 , motor1_pin2 , motor2_pin1 , motor2_pin2 };
  int estado1_2[]   = {      255       ,        255      ,      0      ,      1     ,       1     ,       0    };
  
  for( int i = 0 ; i < sizeof( motor1_2 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor1_2[i],  estado1_2[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor1_2[i] , estado1_2[i] );  
  }
  
  //Motores 3 y 4
  
  String motor3_4[] = { motor3_activar ,  motor4_activar , motor3_pin1 , motor3_pin2 , motor4_pin1 , motor4_pin2 };
  int estado3_4[]   = {      255       ,        255      ,      0      ,      1     ,       1     ,       0    };
  
  for( int i = 0 ; i < sizeof( motor3_4 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor3_4[i],  estado3_4[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor3_4[i] , estado3_4[i] );  
  } 
 
}

/* ---------------------- FRENADOS ----------------------- */

//////////////
void frenado_lento()
{
  //LOW = 0
  //HIGH = 1
  
  //Motores 1 y 2
  
  String motor1_2[] = { motor1_activar ,  motor2_activar , motor1_pin1 , motor1_pin2 , motor2_pin1 , motor2_pin2 };
  int estado1_2[]   = {      255       ,        255      ,      0      ,      0      ,       0     ,       0     };
  
  for( int i = 0 ; i < sizeof( motor1_2 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor1_2[i],  estado1_2[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor1_2[i] , estado1_2[i] );  
  }
  
  //Motores 3 y 4
  
  String motor3_4[] = { motor3_activar ,  motor4_activar , motor3_pin1 , motor3_pin2 , motor4_pin1 , motor4_pin2 };
  int estado3_4[]   = {      255       ,        255      ,      0      ,      0      ,       0     ,       0     };
  
  for( int i = 0 ; i < sizeof( motor3_4 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor3_4[i],  estado3_4[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor3_4[i] , estado3_4[i] );  
  }
  
}//Fin frenado_lento

//////////////
void frenado_rapido()
{
  //LOW = 0
  //HIGH = 1
  
  //Motores 1 y 2
  
  String motor1_2[] = { motor1_activar ,  motor2_activar , motor1_pin1 , motor1_pin2 , motor2_pin1 , motor2_pin2 };
  int estado1_2[]   = {      255       ,        255      ,      1      ,      1      ,       1     ,       1     };
  
  for( int i = 0 ; i < sizeof( motor1_2 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor1_2[i],  estado1_2[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor1_2[i] , estado1_2[i] );  
  }
  
  //Motores 3 y 4
  
  String motor3_4[] = { motor3_activar ,  motor4_activar , motor3_pin1 , motor3_pin2 , motor4_pin1 , motor4_pin2 };
  int estado3_4[]   = {      255       ,        255      ,      1      ,      1      ,       1     ,       1     };
  
  for( int i = 0 ; i < sizeof( motor3_4 ) / 2 ; i++ )
  {
    //Encender(pines "activar")
    analogWrite(  motor3_4[i],  estado3_4[i] );
    
    //Mover en un sentido(adelante/atrás) - (pines "entrada")
	digitalWrite( motor3_4[i] , estado3_4[i] );  
  }
  
}//Fin frenado_rapido

/* ---------------------------------------------- */

//////////////
void serialEvent()
{
  while( Serial.available() ) 
  {
    BT_recibido = Serial.read();
  }
  
  Serial.flush();
  
}//Fin serialEvent

//////////////
bool leer_movimiento()
{
  int movimiento = analogRead( Sensor_movimiento );
  
  if ( movimiento < 0 )
  { 
    return true;
  }
  
}//Fin leer_movimiento

//////////////
void comunicacion()
{
  if ( leer_movimiento() == true )
  {
    Serial.write("Hay un objeto adelante. ");
  }
  
}//Fin comunicacion