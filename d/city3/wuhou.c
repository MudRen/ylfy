// modified by wind
//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG

          ة�����úδ�Ѱ�����ٳ����ɭɭ��
          ӳ�ױ̲��Դ�ɫ����Ҷ�����պ�����
          ����Ƶ�����¼ƣ����������ϳ��ġ�
          ��ʦδ������������ʹӢ��������?
   ������Ǳ����˾����������.���ﰲ��������ʱ����
һ���ͳ������,���гɶ������˺��ο�ǰ���ΰݡ����ܲ�
����������ž޴���Ĺ,�����ϲ�ʱ����������ü������
�������������š���ʦδ����������,���в��ɵ�һ����Ȼ��
����������Ĺ��
LONG
        );

        
        set("valid_startroom", 1);
             set("exits", ([
                "west" : __DIR__"lingmu",
                "east" : __DIR__"beijie1",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}

 
