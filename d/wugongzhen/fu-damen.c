// fu-damen ���Ҵ���
// By csy 1999.03

inherit ROOM;

void create()
{
        set("short", "���Ҵ���");
        set("long", @LONG
�������书�����׸�--��Ա��ҵĴ��ţ����Ϲ���һ�����ң�����
д�š�����������֡���������һ������Ӱ�ڣ�ģģ������������һ
Щʫ��֮��Ķ�����������ü���۵ļҶ���ͦ��͹�ǵ�վ���ſ�ҫ��������
��������һ��Ϊ�����ʵ������аԡ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"dongjie",
                "south" : __DIR__"fu-xiaoyuan",
        ]));
        set("objects", ([
                __DIR__"npc/jiading" : 3,
        ]));

        setup();
        replace_program(ROOM);
}

