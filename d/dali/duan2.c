// Room: /d/dali/duan2.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺20ʱ44��1�롣

inherit ROOM;

void create()
{
	set("short", "������������");
	set("long", @LONG
������ǰ��ֻ�����Ĵ���֮ǰ������˸��ʣ���ͷ��������
����ʯʨ���������ԣ�һ�Ű����ʯֱͨ��ǰ�������ɺ���֮����
�ſ�վ�����ױ���ʿ���䱸ɭ�ϡ�
LONG
	);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"duan1",
  "eastup" : __DIR__"duan3",
]));

                 set("objects", ([
                __DIR__"npc/qingbing" : 2,
        ]));

         
	setup();
}

