#include "CJY901.h"

CJY901::CJY901 ()
{

	rxBuffer = new char[1024];
	rxIndex = 0;
}

CJY901::~CJY901()
{
	delete []rxBuffer;
	rxBuffer = NULL;
}

/*
void CJY901 ::CopeSerialData(char ucData[],unsigned short usLength)
{
	static unsigned char chrTemp[2000];
	static unsigned char ucRxCnt = 0;	
	static unsigned short usRxLength = 0;
    memcpy(chrTemp,ucData,usLength);
	usRxLength += usLength;
    while (usRxLength >= 11)
    {
        if (chrTemp[0] != 0x55)
        {
			usRxLength--;
			memcpy(&chrTemp[0],&chrTemp[1],usRxLength);

            continue;
        }
		switch(chrTemp[1])
		{
			case 0x50:	memcpy(&stcTime,&chrTemp[2],8);break;
			case 0x51:	memcpy(&stcAcc,&chrTemp[2],8);break;
			case 0x52:	memcpy(&stcGyro,&chrTemp[2],8);break;
			case 0x53:	memcpy(&stcAngle,&chrTemp[2],8);break;
			case 0x54:	memcpy(&stcMag,&chrTemp[2],8);break;
			case 0x55:	memcpy(&stcDStatus,&chrTemp[2],8);break;
			case 0x56:	memcpy(&stcPress,&chrTemp[2],8);break;
			case 0x57:	memcpy(&stcLonLat,&chrTemp[2],8);break;
			case 0x58:	memcpy(&stcGPSV,&chrTemp[2],8);break;
		}
		usRxLength -= 11;
		memcpy(&chrTemp[0],&chrTemp[11],usRxLength);                     
    }
}
*/
bool CJY901 ::CopeSerialData(uint8_t ucData)
{
	rxBuffer[rxIndex] = char(ucData);
    rxIndex += 1;

    if (rxBuffer[0] != 0x55)
    {
        cout << "no right start U" << endl;
        //如果发现第一个数据不是界符的话，就将索引置0
        rxIndex = 0;
        return false;
    }
	/*
	else
	{
		cout << "right start U\n";
	}
	*/

    if (rxIndex < 11 )
    {
        //记录数组位置
        //如果数据索引没有到11的话，退出并再次执行本函数
        return false;
    }

	
	//校验和
	/*
	int sum = 0;
	for (size_t i = 0; i < 10; i++)
	{
		sum += int(rxBuffer[i]);
	}
	sum &= 0xff;
	
    if( rxBuffer[10] != sum)
    {
        cout << "no right end sum"  << endl;
        rxIndex = 0;
        return false;
    }
	*/


	//计算
	switch(rxBuffer[1])
	{
		case 0x50:	memcpy(&stcTime,&rxBuffer[2],8);break;
		case 0x51:	memcpy(&stcAcc,&rxBuffer[2],8);break;
		case 0x52:	memcpy(&stcGyro,&rxBuffer[2],8);break;
		case 0x53:	memcpy(&stcAngle,&rxBuffer[2],8);break;
		case 0x54:	memcpy(&stcMag,&rxBuffer[2],8);break;
		case 0x55:	memcpy(&stcDStatus,&rxBuffer[2],8);break;
		case 0x56:	memcpy(&stcPress,&rxBuffer[2],8);break;
		case 0x57:	memcpy(&stcLonLat,&rxBuffer[2],8);break;
		case 0x58:	memcpy(&stcGPSV,&rxBuffer[2],8);break;
		case 0x59:  memcpy(&stcQuater,&rxBuffer[2],8);break;
		case 0x5a:  memcpy(&stcSSN,&rxBuffer[2],8);break;
	}
	rxIndex = 0;
	return true;
}