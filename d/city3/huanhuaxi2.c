//bye enter

inherit ROOM;

void create()
{
        set("short", "佻�Ϫ");
        set("long",@LONG
������Ȼ�Ѿ���������������е����⣬�Ծ���ʮ��
���ȵġ�������һƬܽ������Զɽ��������֮�У���������
�����ˣ���Զ�����ţ�һ�ԴԵ����֣���һ��Ϫ����������
��������ȥ����������佻�Ϫ���������Ǳ�����ˡ�
LONG
        );

        set("outdoors", "/d/chengdu");

        set("exits", ([
                "southwest" : __DIR__"huanhuaxi1",
                "northeast" : __DIR__"beijie1",
            ]));
        setup();
        replace_program(ROOM);       
}


