#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "Base.h"
using namespace std;
// �洢�γ���Ϣ
//�Զ����ʽ����������֤�γ�������һ��
string formatCourseName(const string& name,int width) {
    string formatted = name;
    while (formatted.length() < width) {
        formatted += " ";
    }
    return formatted;
}
map<string, vector<Course>> softwareEngineering = {
    {
        "��һ",
        {
            Course(formatCourseName("�ߵ���ѧ", 20), 95, 12, "����ʦ ", "����1"),
            Course(formatCourseName("���������", 20), 95, 8, "����ʦ ", "����2"),
            Course(formatCourseName("�������ѧ����", 20), 90, 6, "����ʦ ", "����3"),
            Course(formatCourseName("�����ͼ�����", 20), 95, 10, "����ʦ", "����4"),
            Course(formatCourseName("��ɢ��ѧ", 20), 90, 8, "����ʦ ", "����5"),
            Course(formatCourseName("˼������뷨������", 20), 85, 6, "����ʦ ", "����6")
        }
    },
    {
        "���",
        {
            Course(formatCourseName("���ݽṹ", 20), 95, 8, "����ʦ", "����7"),
            Course(formatCourseName("�㷨��������", 20), 95, 8, "Ǯ��ʦ", "����8"),
            Course(formatCourseName("��������ԭ��", 20), 90, 10, "����ʦ", "����9"),
            Course(formatCourseName("����ϵͳ", 20), 95, 10, "����ʦ", "����10"),
            Course(formatCourseName("���ݿ�ϵͳԭ��", 20), 90, 8, "����ʦ", "����11"),
            Course(formatCourseName("���������", 20), 95, 8, "֣��ʦ", "����12")
        }
    },
    {
        "����",
        {
            Course(formatCourseName("������̹���", 20), 95, 8, "����ʦ", "����13"),
            Course(formatCourseName("�����ϵ�ṹ�����ģʽ", 20), 90, 8, "����ʦ", "����14"),
            Course(formatCourseName("�����������ϵ�ṹ", 20), 95, 8, "����ʦ", "����15"),
            Course(formatCourseName("���������������֤", 20), 90, 8, "����ʦ", "����16"),
            Course(formatCourseName("�������ʵ��", 20), 95, 10, "����ʦ", "����17"),
            Course(formatCourseName("�����Ŀ����", 20), 90, 8, "����ʦ", "����18")
        }
    },
    {
        "����",
        {
            Course(formatCourseName("�����ȫ��ɿ���", 20), 95, 6, "����ʦ", "����19"),
            Course(formatCourseName("���簲ȫ�빥������", 20), 90, 6, "Ǯ��ʦ", "����20"),
            Course(formatCourseName("�Ƽ���������ݷ���", 20), 95, 6, "����ʦ", "����21"),
            Course(formatCourseName("�˹������㷨����", 20), 90, 6, "����ʦ", "����22"),
            Course(formatCourseName("��������ۺ�ʵ��", 20), 95, 12, "����ʦ", "����23")
        }
    }
};

map<string, vector<Course>> computerScience = {
    {
        "��һ",
        {
            Course(formatCourseName("�ߵ���ѧ", 20), 100, 12, "����ʦ", "����24"),
            Course(formatCourseName("��ѧ����", 20), 90, 8, "����ʦ", "����25"),
            Course(formatCourseName("רҵӢ��", 20), 90, 6, "����ʦ", "����26"),
            Course(formatCourseName("������ƻ���", 20), 100, 10, "����ʦ", "����27"),
            Course(formatCourseName("�����ͼ�����", 20), 100, 8, "����ʦ", "��   ��28"),
            Course(formatCourseName("˼������뷨������", 20), 100, 8, "����ʦ", "����29")
        }
    },
    {
        "���",
        {
            Course(formatCourseName("��ɢ��ѧ", 20), 90, 8, "����ʦ", "����30"),
            Course(formatCourseName("���ݽṹ", 20), 100, 8, "����ʦ", "����31"),
            Course(formatCourseName("��������ԭ��", 20), 100, 12, "����ʦ", "����32"),
            Course(formatCourseName("����ϵͳ", 20), 100, 12, "����ʦ", "����33"),
            Course(formatCourseName("�������", 20), 100, 8, "����ʦ", "����34"),
            Course(formatCourseName("������", 20), 90, 6, "����ʦ", "����35")
        }
    },
    {
        "����",
        {
            Course(formatCourseName("�㷨��������", 20), 100, 6, "����ʦ", "����36"),
            Course(formatCourseName("����ԭ��", 20), 100, 16, "����ʦ", "����37"),
            Course(formatCourseName("���ݿ�ԭ��", 20), 100, 6, "����ʦ", "����38"),
            Course(formatCourseName("�����ԭ��", 20), 100, 6, "����ʦ", "����39"),
            Course(formatCourseName("���簲ȫ����", 20), 100, 6, "����ʦ", "����40")
        }
    },
    {
        "����",
        {}
    }
};

map<string, vector<Course>> electronicEngineering = {
    {
        "��һ",
        {
            Course(formatCourseName("�ߵ���ѧ", 20), 100, 12, "����ʦ", "����41"),
            Course(formatCourseName("��ѧ����", 20), 90, 8, "����ʦ", "����42"),
            Course(formatCourseName("רҵӢ��", 20), 90, 6, "����ʦ", "����43"),
            Course(formatCourseName("��·ԭ��", 20), 100, 10, "����ʦ", "����44"),
            Course(formatCourseName("������ͼ", 20), 90, 8, "����ʦ", "����45"),
            Course(formatCourseName("˼������뷨������", 20), 100, 8, "����ʦ", "����46")
        }
    },
    {
        "���",
        {
            Course(formatCourseName("ģ����Ӽ���", 20), 100, 8, "����ʦ", "����47"),
            Course(formatCourseName("���ֵ��Ӽ���", 20), 100, 8, "����ʦ", "����48"),
            Course(formatCourseName("�ź�ϵͳ", 20), 100, 12, "����ʦ", "����49"),
            Course(formatCourseName("�Զ�����ԭ��", 20), 100, 12, "����ʦ", "����50"),
            Course(formatCourseName("ͨ��ԭ��", 20), 100, 8, "����ʦ", "����51"),
            Course(formatCourseName("������", 20), 90, 6, "����ʦ", "����52")
        }
    },
    {
        "����",
        {
            Course(formatCourseName("��Ƭ��ԭ��Ӧ��", 20), 100, 6, "����ʦ", "����53"),
            Course(formatCourseName("������ԭ��Ӧ��", 20), 100, 6, "����ʦ", "����54"),
            Course(formatCourseName("Ƕ��ʽϵͳ���", 20), 100, 16, "����ʦ", "����55"),
            Course(formatCourseName("�������Ӽ���", 20), 100, 6, "����ʦ", "����56"),
            Course(formatCourseName("���ӵ�·���", 20), 100, 6, "����ʦ", "����57")
        }
    },
    {
        "����",
        {}
    }
};

map<string, vector<Course>> mechanicalEngineering = {
    {
        "��һ",
        {
            Course(formatCourseName("�ߵ���ѧ", 20), 100, 12, "����ʦ", "����58"),
            Course(formatCourseName("��ѧ����", 20), 90, 8, "����ʦ", "����59"),
            Course(formatCourseName("רҵӢ��", 20), 90, 6, "����ʦ", "����60"),
            Course(formatCourseName("������ͼ", 20), 90, 8, "����ʦ", "����61"),
            Course(formatCourseName("��е��ƻ���", 20), 100, 10, "����ʦ", "����62"),
            Course(formatCourseName("˼������뷨������", 20), 100, 8, "����ʦ", "����63")
        }
    },
    {
        "���",
        {
            Course(formatCourseName("������ѧ", 20), 100, 8, "����ʦ", "����64"),
            Course(formatCourseName("������ѧ", 20), 100, 8, "����ʦ", "����65"),
            Course(formatCourseName("��е���켼������", 20), 100, 12, "����ʦ", "����66"),
            Course(formatCourseName("���紫������", 20), 100, 12, "����ʦ", "����67"),
            Course(formatCourseName("Һѹ����ѹ����", 20), 90, 6, "����ʦ", "����68"),
            Course(formatCourseName("������", 20), 90, 6, "����ʦ", "����69")
        }
    },
    {
        "����",
        {
            Course(formatCourseName("��еԭ��", 20), 100, 6, "����ʦ", "����70"),
            Course(formatCourseName("��е���", 20), 100, 16, "����ʦ", "����71"),
            Course(formatCourseName("��е�Ż����", 20), 100, 6, "����ʦ", "����72"),
            Course(formatCourseName("��е����װ�����", 20), 100, 6, "����ʦ", "����73"),
            Course(formatCourseName("��еϵͳ����ѧ", 20), 100, 6, "����ʦ", "����74")
        }
    },
    {
        "����",
        {}
    }
};

map<string, vector<Course>> civilEngineering = {
    {
        "��һ",
        {
            Course(formatCourseName("�ߵ���ѧ", 20), 100, 12, "����ʦ", "����75"),
            Course(formatCourseName("��ѧ����", 20), 90, 8, "����ʦ", "����76"),
            Course(formatCourseName("רҵӢ��", 20), 90, 6, "����ʦ", "����77"),
            Course(formatCourseName("������ͼ", 20), 90, 8, "����ʦ", "����78"),
            Course(formatCourseName("���̲���ѧ", 20), 100, 10, "����ʦ", "����79"),
            Course(formatCourseName("˼������뷨������", 20), 100, 8, "����ʦ", "����80")
        }
    },
    {
        "���",
        {
            Course(formatCourseName("������ѧ", 20), 100, 8, "����ʦ", "����81"),
            Course(formatCourseName("������ѧ", 20), 100, 8, "����ʦ", "����82"),
            Course(formatCourseName("�ṹ��ѧ", 20), 100, 12, "����ʦ", "����83"),
            Course(formatCourseName("���̵���ѧ", 20), 90, 6, "����ʦ", "����84"),
            Course(formatCourseName("����ѧ", 20), 100, 8, "����ʦ", "����85"),
            Course(formatCourseName("������", 20), 90, 6, "����ʦ", "����86")
        }
    },
    {
        "����",
        {
            Course(formatCourseName("�������ṹ���ԭ��", 20), 100, 6, "����ʦ", "����87"),
            Course(formatCourseName("�ֽṹ���ԭ��", 20), 100, 6, "����ʦ", "����88"),
            Course(formatCourseName("��ľ����ʩ������", 20), 100, 12, "����ʦ", "����89"),
            Course(formatCourseName("���̽ṹ����", 20), 100, 8, "����ʦ", "����90"),
            Course(formatCourseName("����ʩ����֯", 20), 100, 6, "����ʦ", "����91")
        }
    },
    {
        "����",
        {}
    }
};

map<string, vector<Course>> chemistry = {
    {
        "��һ",
        {
            Course(formatCourseName("�ߵ���ѧ", 20), 100, 12, "����ʦ", "����92"),
            Course(formatCourseName("��ѧ����", 20), 90, 8, "����ʦ", "����93"),
            Course(formatCourseName("רҵӢ��", 20), 90, 6, "����ʦ", "����94"),
            Course(formatCourseName("�޻���ѧ", 20), 100, 10, "����ʦ", "����95"),
            Course(formatCourseName("������ѧ", 20), 90, 8, "����ʦ", "����96"),
            Course(formatCourseName("˼������뷨������", 20), 100, 8, "����ʦ", "����97")
        }
    },
    {
        "���",
        {
            Course(formatCourseName("�л���ѧ", 20), 100, 8, "����ʦ", "����98"),
            Course(formatCourseName("����ѧ", 20), 100, 12, "����ʦ", "����99"),
            Course(formatCourseName("��������", 20), 100, 6, "����ʦ", "����100"),
            Course(formatCourseName("�ṹ��ѧ", 20), 100, 6, "����ʦ", "����101"),
            Course(formatCourseName("��ѧʵ�����", 20), 100, 8, "����ʦ", "����102"),
            Course(formatCourseName("������", 20), 90, 6, "����ʦ", "����103")
        }
    },
    {
        "����",
        {
            Course(formatCourseName("�߷��ӻ�ѧ", 20), 100, 6, "����ʦ", "����104"),
            Course(formatCourseName("�߻�ԭ��", 20), 100, 16, "����ʦ", "����105"),
            Course(formatCourseName("�ߵ��л���ѧ", 20), 100, 6, "����ʦ", "����106"),
            Course(formatCourseName("���׷���", 20), 100, 6, "����ʦ", "����107"),
            Course(formatCourseName("�л��ϳɻ�ѧ", 20), 100, 6, "����ʦ", "����108")
        }
    },
    {
        "����",
        {}
    }
};

map<string, vector<Course>> biology = {
    {
        "��һ",
        {
            Course(formatCourseName("�ߵ���ѧ", 20), 100, 12, "����ʦ", "����109"),
            Course(formatCourseName("��ѧ����", 20), 90, 8, "����ʦ", "����110"),
            Course(formatCourseName("רҵӢ��", 20), 90, 6, "����ʦ", "����111"),
            Course(formatCourseName("ֲ��ѧ", 20), 100, 10, "����ʦ", "����112"),
            Course(formatCourseName("����ѧ", 20), 90, 8, "����ʦ", "����113"),
            Course(formatCourseName("˼������뷨������", 20), 100, 8, "����ʦ", "����114")
        }
    },
    {
        "���",
        {
            Course(formatCourseName("���ﻯѧ", 20), 100, 12, "����ʦ", "����115"),
            Course(formatCourseName("ϸ������ѧ", 20), 100, 8, "����ʦ", "����116"),
            Course(formatCourseName("�Ŵ�ѧ", 20), 100, 8, "����ʦ", "����117"),
            Course(formatCourseName("΢����ѧ", 20), 100, 8, "����ʦ", "����118"),
            Course(formatCourseName("��̬ѧ", 20), 90, 6, "����ʦ", "����119"),
            Course(formatCourseName("������", 20), 90, 6, "����ʦ", "����120")
        }
    },
    {
        "����",
        {
            Course(formatCourseName("��������ѧ", 20), 100, 6, "����ʦ", "����121"),
            Course(formatCourseName("���򹤳�", 20), 100, 6, "����ʦ", "����122"),
            Course(formatCourseName("������ҩ", 20), 100, 16, "����ʦ", "����123"),
            Course(formatCourseName("����ͳ��ѧ", 20), 100, 6, "����ʦ", "����124"),
            Course(formatCourseName("��������ѧ", 20), 100, 6, "����ʦ", "����125")
        }
    },
    {
        "����",
        {}
    }
};

map<string, vector<Course>> economics = {
    {
        "��һ",
        {
            Course(formatCourseName("�ߵ���ѧ", 20), 100, 12, "����ʦ", "����126"),
            Course(formatCourseName("רҵӢ��", 20), 90, 6, "����ʦ", "����127"),
            Course(formatCourseName("����ѧԭ��", 20), 100, 10, "����ʦ", "����128"),
            Course(formatCourseName("����ѧԭ��", 20), 90, 8, "����ʦ", "����129"),
            Course(formatCourseName("˼������뷨������", 20), 100, 8, "����ʦ", "����130")
        }
    },
    {
        "���",
        {
            Course(formatCourseName("΢�۾���ѧ", 20), 100, 8, "����ʦ", "����131"),
            Course(formatCourseName("��۾���ѧ", 20), 100, 8, "����ʦ", "����132"),
            Course(formatCourseName("ͳ��ѧ", 20), 100, 8, "����ʦ", "����133"),
            Course(formatCourseName("���ѧ", 20), 100, 8, "����ʦ", "����134"),
            Course(formatCourseName("����ѧ", 20), 90, 6, "����ʦ", "����135"),
            Course(formatCourseName("������", 20), 90, 6, "����ʦ", "����136")
        }
    },
    {
        "����",
        {
            Course(formatCourseName("��������ѧ", 20), 100, 6, "����ʦ", "����137"),
            Course(formatCourseName("���ھ���ѧ", 20), 100, 6, "����ʦ", "����138"),
            Course(formatCourseName("��ҵ����ѧ", 20), 100, 16, "����ʦ", "����139"),
            Course(formatCourseName("Ͷ��ѧ", 20), 100, 6, "����ʦ", "����140"),
            Course(formatCourseName("��չ����ѧ", 20), 100, 6, "����ʦ", "����141")
        }
    },
    {
        "����",
        {}
    }
};

map<string, vector<Course>> management = {
    {
        "��һ",
        {
            Course(formatCourseName("�ߵ���ѧ", 20), 100, 12, "����ʦ", "����142"),
            Course(formatCourseName("רҵӢ��", 20), 90, 6, "����ʦ", "����143"),
            Course(formatCourseName("����ѧԭ��", 20), 100, 10, "����ʦ", "����144"),
            Course(formatCourseName("��������ѧ", 20), 90, 8, "����ʦ", "����145"),
            Course(formatCourseName("˼������뷨������", 20), 100, 8, "����ʦ", "����146")
        }
    },
    {
        "���",
        {
            Course(formatCourseName("��֯��Ϊѧ", 20), 100, 8, "����ʦ", "����147"),
            Course(formatCourseName("������Դ����", 20), 100, 8, "����ʦ", "����148"),
            Course(formatCourseName("�г�Ӫ��ѧ", 20), 100, 8, "����ʦ", "����149"),
            Course(formatCourseName("�������", 20), 100, 8, "����ʦ", "����150"),
            Course(formatCourseName("ͳ��ѧ", 20), 90, 6, "����ʦ", "����151"),
            Course(formatCourseName("������", 20), 90, 6, "����ʦ", "����152")
        }
    },
    {
        "����",
        {
            Course(formatCourseName("ս�Թ���", 20), 100, 6, "����ʦ", "����153"),
            Course(formatCourseName("������Ϣϵͳ", 20), 100, 6, "����ʦ", "����154"),
            Course(formatCourseName("��Ŀ����", 20), 100, 16, "����ʦ", "����155"),
            Course(formatCourseName("���ز߻�", 20), 100, 6, "����ʦ", "����156"),
            Course(formatCourseName("��Ӫ����", 20), 100, 6, "����ʦ", "����157")
        }
    },
    {
        "����",
        {}
    }
};

map<string, vector<Course>> journalism = {
    {
        "��һ",
        {
            Course(formatCourseName("רҵӢ��", 20), 90, 6, "����ʦ", "����158"),
            Course(formatCourseName("����ѧ����", 20), 100, 10, "����ʦ", "����159"),
            Course(formatCourseName("����ѧ����", 20), 90, 8, "����ʦ", "����160"),
            Course(formatCourseName("�й�������ҵʷ", 20), 100, 8, "����ʦ", "����161"),
            Course(formatCourseName("˼������뷨������", 20), 100, 8, "����ʦ", "����162")
        }
    },
    {
        "���",
        {
            Course(formatCourseName("���Ųɷ���д��", 20), 100, 8, "����ʦ", "����163"),
            Course(formatCourseName("���ű༭������", 20), 100, 8, "����ʦ", "����164"),
            Course(formatCourseName("������Ӱ", 20), 90, 6, "����ʦ", "����165"),
            Course(formatCourseName("�㲥��������ѧ", 20), 100, 8, "����ʦ", "����166"),
            Course(formatCourseName("��������ý�����", 20), 100, 8, "����ʦ", "����167"),
            Course(formatCourseName("������", 20), 90, 6, "����ʦ", "����168")
        }
    },
    {
        "����",
        {
            Course(formatCourseName("��������ѧ", 20), 100, 6, "����ʦ", "����169"),
            Course(formatCourseName("����ְҵ������ְҵ����", 20), 100, 6, "����ʦ", "����170"),
            Course(formatCourseName("ý�龭Ӫ�����", 20), 100, 16, "����ʦ", "����171"),
            Course(formatCourseName("������Ӱ������", 20), 100, 6, "����ʦ", "����172"),
            Course(formatCourseName("���Ŵ���ǰ���о�", 20), 100, 6, "����ʦ", "����173")
        }
    },
    {
        "����",
        {}
    }
};

map<string, vector<Course>> law = {
    {
        "��һ",
        {
            Course(formatCourseName("רҵӢ��", 20), 90, 6, "����ʦ", "����174"),
            Course(formatCourseName("��ѧ����", 20), 100, 10, "����ʦ", "����175"),
            Course(formatCourseName("�й�����ʷ", 20), 90, 8, "����ʦ", "����176"),
            Course(formatCourseName("����ѧ", 20), 100, 8, "����ʦ", "����177"),
            Course(formatCourseName("˼������뷨������", 20), 100, 8, "����ʦ", "����178")
        }
    },
    {
        "���",
        {
            Course(formatCourseName("�ܷ�ѧ", 20), 100, 8, "����ʦ", "����179"),
            Course(formatCourseName("��ѧ", 20), 100, 8, "����ʦ", "����180"),
            Course(formatCourseName("�̷�ѧ����", 20), 100, 8, "����ʦ", "����181"),
            Course(formatCourseName("�̷�ѧ����", 20), 100, 8, "����ʦ", "����182"),
            Course(formatCourseName("���������������Ϸ�", 20), 100, 8, "����ʦ", "����183"),
            Course(formatCourseName("������", 20), 90, 6, "����ʦ", "����184")
        }
    },
    {
        "����",
        {
            Course(formatCourseName("�������Ϸ�ѧ", 20), 100, 6, "����ʦ", "����185"),
            Course(formatCourseName("֪ʶ��Ȩ��", 20), 100, 6, "����ʦ", "����186"),
            Course(formatCourseName("�̷�ѧ", 20), 100, 16, "����ʦ", "����187"),
            Course(formatCourseName("���÷�ѧ", 20), 100, 6, "����ʦ", "����188"),
            Course(formatCourseName("���ʾ��÷�ѧ", 20), 100, 6, "����ʦ", "����189")
        }
    },
    {
        "����",
        {}
    }
};

map<string, map<string, vector<Course>>> course = {
    {"�������",softwareEngineering},
    {"�������ѧ�뼼��",computerScience},
    {"���ӹ���",electronicEngineering},
    {"��е����",mechanicalEngineering},
    {"��ľ����",civilEngineering},
    {"��ѧ",chemistry},
    {"����ѧ",biology},
    {"����ѧ",economics},
    {"����ѧ",management},
    {"����ѧ",journalism},
    {"��ѧ",law}
};
