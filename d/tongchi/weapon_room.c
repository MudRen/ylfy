inherit ROOM;
void create()
{
          set("short", "������");
        set("long", @LONG
СС�ı���������ȴ�����Ÿ�ʽ�����ı��������в�������������
��ͨ�԰���Ӷ�������ѡ���Լ��ı�����
LONG
        );
        set("exits", ([
                   "west" : __DIR__"tianjin",
        ]));
        set("objects", ([
        ]));
        set("no_fight", "1");
        setup();
        replace_program(ROOM);
}
