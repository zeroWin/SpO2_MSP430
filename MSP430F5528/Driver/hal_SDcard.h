#ifndef	__SDcard_H
#define	__SDcard_H

//////////////////////////////////////////////////////////////////////////////////

//����˵��

//////////////////////////////////////////////////////////////////////////////////	
//---------------------------ͷ�ļ�--------------------------
#include "hal_type.h"
#include "msp430f5528.h"
//---------------------------SD�����Ͷ��� -------------------------- 
#define SD_TYPE_ERR     0X00		//�޿��򿨲���ʶ��
#define SD_TYPE_MMC     0X01		//MMC��
#define SD_TYPE_V1      0X02		//ʹ��V1.0��׼��SD��
#define SD_TYPE_V2      0X04		//ʹ��V2.0��׼��SD��
#define SD_TYPE_V2HC    0X06	 	//V2.0HC���ٿ�

//--------------------------- SD��ָ���-------------------------- 
#define CMD0    0       //����λ
#define CMD1    1		//����1 ����OCR�Ĵ���
#define CMD8    8       //����8 ��SEND_IF_COND ֻ��V2.0�����и�����������ж�SD�����ͣ�����0x01��V2.0������0x01����V2.0
#define CMD9    9       //����9 ����CSD����
#define CMD10   10      //����10����CID����
#define CMD12   12      //����12��ֹͣ���ݴ���
#define CMD16   16      //����16������SectorSize Ӧ����0x00
#define CMD17   17      //����17����sector
#define CMD18   18      //����18����Multi sector
#define CMD23   23      //����23�����ö�sectorд��ǰԤ�Ȳ���N��block
#define CMD24   24      //����24��дsector
#define CMD25   25      //����25��дMulti sector
#define CMD41   41      //����41��Ӧ����0x00	��ACOM41
#define CMD55   55      //����55��Ӧ����0x01 CMD55��ʾ��һ����Ӧ��ָ�ACMD CMD55+CMD41��������ж���V1.0����MMC�� 
#define CMD58   58      //����58����OCR��Ϣ	��31λ�������ж�V2.0���Ƿ�ΪSDHC����
#define CMD59   59      //����59��ʹ��/��ֹCRC��Ӧ����0x00

//--------------------------- ����д���Ӧ������ -------------------------- 
#define MSD_DATA_OK                0x05
#define MSD_DATA_CRC_ERROR         0x0B
#define MSD_DATA_WRITE_ERROR       0x0D
#define MSD_DATA_OTHER_ERROR       0xFF

//--------------------------- SD����Ӧ����� -------------------------- 
#define MSD_RESPONSE_NO_ERROR      0x00
#define MSD_IN_IDLE_STATE          0x01
#define MSD_ERASE_RESET            0x02
#define MSD_ILLEGAL_COMMAND        0x04
#define MSD_COM_CRC_ERROR          0x08
#define MSD_ERASE_SEQUENCE_ERROR   0x10
#define MSD_ADDRESS_ERROR          0x20
#define MSD_PARAMETER_ERROR        0x40
#define MSD_RESPONSE_FAILURE       0xFF

//--------------------------- SD��CS�˿ڼ������궨�� -------------------------- 
#define	SD_GPIO_CS_PORT							1
#define SD_CS_GPIO_PIN							2		//P1.2:CS

#define SD_CS_H P3OUT |= (1 << 2)	// P3.2 CS = 1 
#define SD_CS_L P3OUT &= ~(1 << 2)      // p3.2 CS = 0

//--------------------------- ��ض�ֵ�궨�� -------------------------- 
#define DUMMY_DATA 0xFF			//����SD��ʶ�������ֵ�����ڲ���ʱ���ź�
#define UNKNOW_ERROR 0xAA		//δ֪����

//---------------------------��ر�������-------------------------- 
extern uint8  SD_Type;//SD��������


//SDcard���ƺ���
uint8 SD_Initialize(void);//SD��س�ʼ��
uint8 SD_ReadDisk(uint8*buf,uint32 sector,uint8 cnt);//��SD����������
uint8 SD_WriteDisk(uint8*buf,uint32 sector,uint8 cnt);//дSD����������

uint32 SD_GetSectorCount(void);//�õ�SD��������������������
uint8 SD_GetCSD(uint8 *csd_data);//�õ�SD����CSD��Ϣ
uint8 SD_GetCID(uint8 *cid_data);//��ȡSD����CID��Ϣ
uint8 SD_WaitReady(void);//�ȴ�SD��׼����

void SD_SPI_SpeedLow(void);//���õ���ģʽ	
void SD_SPI_SpeedHigh(void);//���ø���ģʽ
uint8 SD_SPI_ReadWriteByte(uint8 data);//��SD�����ͽ��յ��ֽ�����

#endif