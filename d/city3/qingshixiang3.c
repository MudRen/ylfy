//bye enter

inherit ROOM;

void create()
{
        set("short", "��ʯ��ͷ");
        set("long",@LONG
��������ʯ��ľ�ͷ���������ǳɶ����¼ҵĸ�ۡ����
˵������˲���ôϲ�����˴��ţ��㻹�ǿ���뿪�ɡ�
LONG
        );

        set("exits", ([
                "west" : __DIR__"qingshixiang2",
                "north" : __DIR__"wenzai/gate",
            ]));
        setup();
        replace_program(ROOM);       
}


