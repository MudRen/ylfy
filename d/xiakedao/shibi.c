// shibi.c ʯ��

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�����ǰ�ǿ��ĥ�⻬�Ĵ�ʯ��(shibi)�� ʯ�ڱ��ϵ�ȼ�Ű˸�
���ѣ���ҫ������ʯ��������ʮ���ˣ��е�עĿ��˼���еĴ�����
�����еı�Ŀ��������м����ڴ������硣
LONG );
        set("item_desc",([
                "shibi"  :
"\n\t"HIW"ʯ��������ʫ��"NOR"\n\n"
"\t�ˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡ�\n"
"\t�ˡˡ�\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t�ˡˡˡ�\n"
"\t�ˡˡ�\t\t\t\t\t\t\t\t\t\t"HIW"������"+NOR"\t\t\t\t\t\t\t\t\t\t\t\t\t�ˡˡˡ�\n"
"\t�ˡˡ�\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t�ˡˡˡ�\n"
"\t�ˡˡ�\t"RED"�Կ��Ϻ�ӧ���⹳˪ѩ���������հ����������ǡ�"NOR"\t�ˡˡˡ�\n"
"\t�ˡˡ�\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t�ˡˡˡ�\n"
"\t�ˡˡ�\t"HIG"ʮ��ɱһ�ˣ�ǧ�ﲻ���У����˷���ȥ�������������"NOR"\t�ˡˡˡ�\n"
"\t�ˡˡ�\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t�ˡˡˡ�\n"
"\t�ˡˡ�\t"YEL"�й����������ѽ�ϥǰ�ᡣ������캥������Ȱ������"NOR"\t�ˡˡˡ�\n"
"\t�ˡˡ�\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t�ˡˡˡ�\n"
"\t�ˡˡ�\t"HIM"������Ȼŵ��������Ϊ�ᡣ�ۻ����Ⱥ�������������"NOR"\t�ˡˡˡ�\n"
"\t�ˡˡ�\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t�ˡˡˡ�\n"
"\t�ˡˡ�\t"HIC"���Իӽ𴸣��������𾪣�ǧ���׳ʿ���Ӻմ����ǡ�"NOR"\t�ˡˡˡ�\n"
"\t�ˡˡ�\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t�ˡˡˡ�\n"
"\t�ˡˡ�\t"HIY"���������㣬��������Ӣ��˭������£�����̫������"NOR"\t�ˡˡˡ�\n"
"\t�ˡˡ�\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t�ˡˡˡ�\n"
"\t�ˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡ�\n",
        ]));
        set("exits", ([
                "west" : __DIR__"neiting",
                "out"  : __DIR__"shimen",
                "east" : __DIR__"wuchang",
                "south" : __DIR__"xiaowu",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
