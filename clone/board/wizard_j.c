// wizard_j.c
inherit BULLETIN_JBOARD;
void create()
{
        set_name("��ʦ�������ȱ���", ({ "job board", "board","thousand-gold" }) );
	set("location", "/d/wizard/wizard_job");
	set("board_id", "wizard_j");
	set("long",	"����һ����������԰幩��ʦ�����Լ��Ĺ������ȡ�\n" );
	setup();
	set("unit","��");
//        replace_program(BULLETIN_JBOARD);
}
string short()
{
    if (!wizardp(this_player())) return "����һ��"+HIY+"һǧ���Ľ�Ʊ"+NOR+"(Thousand-gold)";
    return ::short();
}

string long()
{
    if (!wizardp(this_player())) return "һ�����ֵһǧ�����ӵĽ�Ʊ��\n";
    return ::long();
}
int do_project(string arg)
{
    if (!wizardp(this_player())) return 0;
    return ::do_project(arg);
}

int do_report(string arg)
{
    if (!wizardp(this_player())) return 0;
    return ::do_report(arg);
}

int do_read(string arg)
{
    if (!wizardp(this_player())) return 0;
    return ::do_read(arg);
}
int do_terminate(string arg)
{
    if (!wizardp(this_player())) return 0;
    return ::do_terminate(arg);
}
