//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "�����Ŷ�����");
        set("long", @LONG
��������������µĳ����Ŷ����ꡣ����������İڷ���
ʮ���ź��᷽����һ����˾�������Ʒ�������Ŷ�����������
��æ������ͷת��.��̨�ϰ�����̳������족��һ�����̣���
������ŵľ��ǳ����š��������и�������
LONG
        );

        set("exits", ([
                "west" : __DIR__"beijie1",                
                "east" : __DIR__"chufang",
        ]));
        set("objects", ([
                "/d/city3/npc/mapo" : 1,
        ]));
      
        setup();
        replace_program(ROOM);
}

 
