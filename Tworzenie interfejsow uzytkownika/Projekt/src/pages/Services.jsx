export default function Services() {
    const services = [
        {
            icon: '📦',
            title: 'Zarządzanie magazynem',
            desc: 'Dodawaj, edytuj i usuwaj części oraz kontroluj ich stan w czasie rzeczywistym.',
        },
        {
            icon: '🔔',
            title: 'Powiadomienia o brakach',
            desc: 'Otrzymuj alerty o niskim stanie magazynowym i minimalnych progach zapasów.',
        },
        {
            icon: '📊',
            title: 'Raporty i analizy',
            desc: 'Generuj raporty zużycia i analizuj dane, aby lepiej zarządzać zaopatrzeniem.',
        },
        {
            icon: '🔗',
            title: 'Integracje z API',
            desc: 'Łącz się z systemami zewnętrznymi – ERP, fakturowanie, zamówienia online.',
        },
        {
            icon: '👥',
            title: 'Zarządzanie użytkownikami',
            desc: 'Twórz konta pracowników, nadawaj role i monitoruj aktywność.',
        },
        {
            icon: '🔒',
            title: 'Bezpieczeństwo danych',
            desc: 'Kopie zapasowe, szyfrowanie, autoryzacja – Twoje dane są zawsze chronione.',
        },
    ];

    return (
        <div className="max-w-6xl mx-auto px-6 py-16">
            <h1 className="text-4xl font-bold text-gray-800 mb-8 text-center">Nasze usługi</h1>

            <p className="text-lg text-gray-700 mb-12 text-center max-w-3xl mx-auto">
                Nasz system magazynowy oferuje szeroki wachlarz funkcji wspierających codzienną pracę
                mechaników, logistyków oraz zarządców części samochodowych.
            </p>

            <div className="grid sm:grid-cols-2 lg:grid-cols-3 gap-8">
                {services.map((item) => (
                    <div
                        key={item.title}
                        className="bg-white shadow-lg hover:shadow-2xl rounded-xl p-6 transition-all duration-300 transform hover:scale-[1.03] text-center border-t-4 border-blue-600"
                    >
                        <div className="text-5xl mb-4">{item.icon}</div>
                        <h2 className="text-lg font-bold text-gray-800 mb-2">{item.title}</h2>
                        <p className="text-gray-600 text-sm">{item.desc}</p>
                    </div>
                ))}
            </div>
        </div>
    );
}
