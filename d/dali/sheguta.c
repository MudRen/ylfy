 // Room: /d/dali/npc/mazumiao.c
// Data: ����˹(hades)
// Time: ��Ԫ��1999��4��21�գ�����ʱ�䣺17ʱ46��28�롣

inherit ROOM;

void create()
{
        set("short", "�߹���");
        set("long", @LONG
�߹���λ�ڴ������ڣ����ڵ��ɽб���嶫�¡��ഫ����������
�������١�����β�����ڣ���ˮ���ģ�����ʿ�γ��ֻ�����������
��ͬ���ھ������˽�������ˮ�ƣ����߹ǻ�����ˮ����Ϣ��
    ����һ���ܴ�ʽ����ש����
LONG
        );
    set("no_fight", "1");
    set("no_steal", "1");
    set("no_sleep_room", "1");
        set("valid_startroom","1");
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xbdajie2",
]));

        set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/youke" : 2,
]));

        setup();
}
void init()
{
    if (!wizardp(this_user()))
    add_action("discmds",({"duanlian","ansuan","touxi","persuade","teach","exert","exercise","study","learn","sleep","kill","steal","cast","conjure","expell","fight","hit","perform","prcatice","scribe","surrender"}));
}
int discmds()
{
    tell_object(this_player(),"�󵨣���ʥ֮���������������\n");
    return 1;
}