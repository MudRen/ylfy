//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������һ����������ʯ�����,�������˺ܶ�,��������
����,�����ĺ�,���ǲ�ʱ���������Ĵ����е��໰,"�����
��","���˰��",�������ǲ���һ����������Ŷ,ֻ�ǿ�ͷ��
���Ŷ���!������һ���鱦�꣬������һ��ĳ���
LONG
        );

        set("exits", ([
                "north" : __DIR__"beijie1",
                "south" : __DIR__"guangchang",
               "east" : __DIR__"duchang",
                "west" : __DIR__"zhubaodian",                
        ]));
        set("outdoors","chengdu");
      
        setup();
        replace_program(ROOM);
}

 
