//by enter

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����ֹᴩ�ɶ����С����������ؽֶ�����Ǯ���Ƶľ�
¥�����ݣ������ֳ�Ϊ����ʳ�֡�����������������ֳ̼�Ⱥ��
�������ﳵ���������������У�ҹ���ǹ���£��ƻ�ͨ�����ϱ�
���ǳɶ���������ҵ���ģ�����·�������и���ջ��
LONG
        );

        set("exits", ([
                "north" : __DIR__"kedian",
                "south" : __DIR__"chunxilu",
                "west" : __DIR__"guangchang",
                "east" : __DIR__"dongjie2",                
        ]));
        set("outdoors","chengdu");
      
        setup();
        replace_program(ROOM);
}

 
