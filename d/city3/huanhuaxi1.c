//bye enter

inherit ROOM;

void create()
{
        set("short", "佻�Ϫ��");
        set("long",@LONG
������佻�Ϫ�ߣ���ˮ�峺���ӱ߲���Ů���ڴ�ϴ�£��Բ�
���������ѵ�СϪ��˳���Ǹ��Ϻ�������ˮ�������м��������
չ��֦�⣬�����ˮ����һ�ɵ�����ʫ�⡣�����ɪ��֦ҡӰб
���ھ����У�����һ˿������¶��� 
LONG
        );

        set("outdoors", "/d/chengdu");

        set("exits", ([
                "south" : __DIR__"cdta",
                "northeast" : __DIR__"huanhuaxi2",
            ]));
        setup();
        replace_program(ROOM);       
}


