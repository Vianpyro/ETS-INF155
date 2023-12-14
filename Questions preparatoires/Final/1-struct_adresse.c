typedef struct {
    unsigned int no_civique;
    char rue[25],
        ville[25],
        province[25],
        code_postal[7];
} t_adresse;

typedef struct {
    unsigned int numero,
        nb_pieces,
        est_chauffe;
} t_appartement;

typedef struct {
    t_adresse adresse;
    t_appartement appartement;
    unsigned int nb_appart;
} t_bloc;
