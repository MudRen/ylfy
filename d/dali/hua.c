inherit ROOM;
void create()
{
        set("short", "���ϻ�");
        set("long", @LONG
���ϻ�����ˮ����ѿ��
ǳ��ˮ������ۣ�Ũ���������ϼ���������ɼҡ�
�����ף����������ڡ�
ˮ��������ޣ���������ů��������˼���ޡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"cao",
  "north" : __DIR__"jiu",
]));
set("objects", ([ 	
__DIR__"npc/afei" : 1,	
__DIR__"npc/lin" : 1,	
]));	

        setup();
}
