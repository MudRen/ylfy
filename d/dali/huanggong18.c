// Room: /d/dali/huanggong18.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "[1;33m������[2;37;0m");
	set("long", @LONG
������չ��ʡ�������������������ͨ��������������æ��Ϊ
����׼����͡��������ݵ���ζ���ȣ��㲻��Ҳ���(serve) һ��
���ˡ�
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"huanggong16",
]));

	setup();
}

