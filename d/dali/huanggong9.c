// Room: /d/dali/huanggong9.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��18�գ�����ʱ�䣺21ʱ27��26�롣

inherit ROOM;

void create()
{
	set("short", "����԰");
	set("long", @LONG
�����Ǵ���ʹ�������԰��԰�ڵĲ軨�������ޡ��軨�Ǵ����
���������ʹ��ڵĲ軨��������ϡ�У���������֮����������һָ��
԰�з��ż�����ź����ϡ����ˡ����ܵ��ʹ������϶��ż������ȣ�
�����ʵ���˯֮ǰ�������������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"huanggong8",
]));

                 set("objects", ([
                __DIR__"npc/taijian" : 2,
        ]));

         
	setup();
}

