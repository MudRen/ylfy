// cuipinggu.c ������
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǰ��һ����������Ĵ�ɽ�ڣ�ɽ���������дж�������һ�ۿ�
��ȥ��ȫ��һƬ����ɫ������Ǵ˵����д����ȵ����������������
���ϣ��͵�������ɽ�ϵİ������ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "southdown" : __DIR__"shanlu3",
                "northup" : __DIR__"baishulin1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

